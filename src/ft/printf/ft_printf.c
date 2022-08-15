/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:59:06 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/15 19:46:50 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <limits.h>
#include <stdarg.h>
#include <unistd.h>

#include "fto_va_va_list.h"

int	ft_printf(const char *format, ...)
{
	t_fto_va	*va;
	va_list		args;
	size_t		length;
	int			result;

	va_start(args, format);
	va = (t_fto_va *)new_fto_va_va_list(&args, true);
	va_end(args);
	if (
		!va
		|| ft_printf_va_fd(STDOUT_FILENO, &length, format, va)
		|| length > INT_MAX
	)
		result = -1;
	else
		result = length;
	if (va)
		va->v->free(va);
	return (result);
}
