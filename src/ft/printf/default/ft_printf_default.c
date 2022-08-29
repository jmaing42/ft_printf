/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_default.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:02:30 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/30 00:53:08 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_default.h"

#include <stdlib.h>

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

t_err	ft_printf_default(t_ft_printf_options *out)
{
	out->context = init_context();
	if (!out->context)
		return (true);
	out->parse_conversion_specifier
		= ft_printf_default_options_parse_conversion_specifier;
	out->parse_length_modifier
		= ft_printf_default_options_parse_length_modifier;
	out->parse_flags
		= ft_printf_default_options_parse_flags;
	return (false);
}
