/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_buffered_out_v_write.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 08:47:40 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/27 23:02:03 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_buffered_out_v.h"

#include "ft_memory.h"

static t_err	buffer_is_enough(
	t_fto_stream_buffered_out *self,
	const char *buffer,
	size_t length,
	size_t *wrote_bytes
)
{
	*wrote_bytes = length;
	ft_memcpy(
		&self->buffer[self->buffer_size],
		buffer,
		length);
	self->buffer_size += length;
	return (
		self->buffer_size == self->buffer_capacity
		&& fto_stream_buffered_out_v_flush(self)
	);
}

static t_err	data_is_big(
	t_fto_stream_buffered_out *self,
	const char *buffer,
	size_t length,
	size_t *wrote_bytes
)
{
	*wrote_bytes = 0;
	return (
		fto_stream_buffered_out_v_flush(self)
		|| self->stream->v->write(
			self->stream,
			buffer,
			length,
			wrote_bytes
		)
	);
}

static t_err	none_of_these(
	t_fto_stream_buffered_out *self,
	const char *buffer,
	size_t length,
	size_t *wrote_bytes
)
{
	const size_t	to_buffer = self->buffer_capacity - self->buffer_size;
	t_err			result;

	if (
		fto_stream_buffered_out_v_write(
			self,
			buffer,
			to_buffer,
			wrote_bytes
		)
	)
		return (true);
	result
		= fto_stream_buffered_out_v_write(
			self,
			buffer + to_buffer,
			length - to_buffer,
			wrote_bytes);
	(*wrote_bytes) += to_buffer;
	return (result);
}

t_err	fto_stream_buffered_out_v_write(
	t_fto_stream_buffered_out *self,
	const char *buffer,
	size_t length,
	size_t *wrote_bytes
)
{
	if (self->buffer_size + length <= self->buffer_capacity)
		return (buffer_is_enough(self, buffer, length, wrote_bytes));
	if (self->buffer_size + length >= self->buffer_capacity * 2)
		return (data_is_big(self, buffer, length, wrote_bytes));
	else
		return (none_of_these(self, buffer, length, wrote_bytes));
}
