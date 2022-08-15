/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_va_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:47:03 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/15 19:53:40 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdlib.h>

#include "ft_io.h"

t_err	ft_printf_va_fd(
	int fd,
	size_t *out_length,
	const char *format,
	t_fto_va *va
)
{
	char	*string;
	size_t	length;
	t_err	result;

	result = (
			ft_printf_va_string(&string, &length, format, va)
			|| !string
			|| ft_write(fd, string, length));
	if (out_length)
		*out_length = length;
	if (string)
		free(string);
	return (result);
}
