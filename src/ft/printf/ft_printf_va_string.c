/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_va_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 00:48:03 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/27 00:54:11 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdlib.h>

#include "fto_stream_string_out.h"

#define BUFFER_SIZE 1024

t_err	ft_printf_va_string(
	char **out,
	size_t *out_length,
	t_ft_printf_input input,
	t_ft_printf_options *options
)
{
	t_fto_stream_string_out	*stream;
	t_err					result;
	size_t					length;

	result = (
			(stream = new_fto_stream_string_out(BUFFER_SIZE)) == NULL
			|| ft_printf_va_stream((t_fto_stream_out *)stream, input, options)
			|| (*out = stream->v.v->to_string(stream, &length)) == NULL);
	if (out_length)
		*out_length = length;
	if (stream)
		stream->v.v->unsafe_free(stream);
	return (result);
}
