/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_va_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:47:03 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/15 20:58:06 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdlib.h>

#include "ft_io.h"

t_err	ft_printf_va_fd(
	int fd,
	size_t *out_length,
	t_ft_printf_input input,
	t_ft_printf_options *options
)
{
	char	*string;
	size_t	length;
	t_err	result;

	result = (
			ft_printf_va_string(&string, &length, input, options)
			|| !string
			|| ft_write(fd, string, length));
	if (out_length)
		*out_length = length;
	if (string)
		free(string);
	return (result);
}
