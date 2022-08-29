/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:59:06 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/30 00:54:19 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <limits.h>
#include <stdarg.h>
#include <unistd.h>

#include "fto_va_va_list.h"

#define FT_PRINTF_ERROR -42

int	ft_printf(const char *format, ...)
{
	t_ft_printf_input	input;
	va_list				args;
	size_t				length;
	int					result;
	t_ft_printf_options	options;

	if (!ft_printf_default(&options))
		return (FT_PRINTF_ERROR);
	input.format = format;
	va_start(args, format);
	input.va = (t_fto_va *)new_fto_va_va_list(&args, true);
	va_end(args);
	if (
		!input.va
		|| ft_printf_va_fd(STDOUT_FILENO, &length, input, &options)
		|| length > INT_MAX
	)
		result = FT_PRINTF_ERROR;
	else
		result = length;
	if (input.va)
		input.va->v->free(input.va);
	options.context->dispose(options.context);
	return (result);
}
