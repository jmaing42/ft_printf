/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_default.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:02:30 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/15 21:53:25 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_default.h"

#include <stdlib.h>

static void	dispose_options(t_ft_printf_options *self)
{
	if (self->context)
		self->context->dispose(self->context);
	free(self);
}

static void	dispose_context(t_ft_printf_options_disposable *self)
{
	free(self);
}

static void	*init_context(void)
{
	t_ft_printf_options_disposable *const	result
		= malloc(sizeof(t_ft_printf_options_disposable));

	if (!result)
		return (NULL);
	result->dispose = dispose_context;
	return (result);
}

t_ft_printf_options	*ft_printf_default(void)
{
	t_ft_printf_options *const	result
		= malloc(sizeof(t_ft_printf_options));

	if (!result)
		return (NULL);
	result->context = init_context();
	if (!result->context)
	{
		free(result);
		return (NULL);
	}
	result->dispose = dispose_options;
	result->parse_conversion_specifier
		= ft_printf_default_options_parse_conversion_specifier;
	result->parse_length_modifier
		= ft_printf_default_options_parse_length_modifier;
	result->parse_flags
		= ft_printf_default_options_parse_flags;
	return (result);
}
