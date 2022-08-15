/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:59:06 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/15 20:58:57 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <limits.h>
#include <stdarg.h>
#include <unistd.h>

#include "fto_va_va_list.h"

int	ft_printf(const char *format, ...)
{
	t_ft_printf_input	input;
	va_list				args;
	size_t				length;
	int					result;

	input.format = format;
	va_start(args, format);
	input.va = (t_fto_va *)new_fto_va_va_list(&args, true);
	va_end(args);
	if (
		!input.va
		|| ft_printf_va_fd(
			STDOUT_FILENO,
			&length,
			input,
			ft_printf_get_default_options())
		|| length > INT_MAX
	)
		result = -42;
	else
		result = length;
	if (input.va)
		input.va->v->free(input.va);
	return (result);
}
