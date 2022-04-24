/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer_buffered_internal.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:58:15 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/24 13:47:30 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_writer_buffered_internal.h"

#include <stdlib.h>
#include <unistd.h>

#include "ft_memory.h"
#include "ft_writer_internal.h"

static void	writer_unsafe_delete(t_writer_buffered *self)
{
	free(self);
}

static t_err	writer_flush(t_writer_buffered *self, t_exception **exception)
{
	if (self->length
		&& self->writer->v->write(
			self->writer, self->buffer, self->length, exception))
	{
		if (exception && *exception)
			(*exception)->b->add_stacktrace(
				*exception, __FILE__, __LINE__, NULL);
		return (true);
	}
	self->length = 0;
	return (false);
}

static t_err	writer_write(
	t_writer_buffered *self,
	const void *buffer,
	size_t len,
	t_exception **exception
)
{
	const size_t	tmp = self->capacity - self->length;

	if (self->length + len < self->capacity)
	{
		ft_memcpy(&self->buffer[self->length], buffer, len);
		self->length += len;
	}
	else if (self->length + len >= self->capacity * 2)
	{
		if (writer_flush(self, exception)
			|| self->writer->v->write(self->writer, buffer, len, exception))
		{
			if (exception && *exception)
				(*exception)->b->add_stacktrace(
					*exception, __FILE__, __LINE__, NULL);
			return (true);
		}
	}
	else
		return (writer_write(self, (char *) buffer + tmp, tmp, exception)
			|| writer_write(self, (char *) buffer + tmp, tmp, exception));
	return (false);
}

static const t_writer_vtable	g_v = {
	(t_writer_v_unsafe_delete)(&writer_unsafe_delete),
	(t_writer_v_write)(&writer_write),
	(t_writer_v_flush)(&writer_flush),
	(t_writer_v_delete)(&ft_writer_base_v_default_delete)
};

t_writer	*new_writer_buffered(t_writer *writer, size_t buffer_size)
{
	t_writer_buffered	*result;

	if (!writer || !buffer_size)
		return (NULL);
	result = (t_writer_buffered *) malloc(
			sizeof(t_writer_buffered) + buffer_size);
	if (!result)
		return (NULL);
	result->expose.v = &g_v;
	result->writer = writer;
	result->capacity = buffer_size;
	result->length = 0;
	return ((t_writer *) result);
}
