/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:58:15 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 15:33:19 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_writer_count.h"

#include <stdlib.h>
#include <unistd.h>

#include "../libft/ft_memory.h"
#include "../libft/ft_writer_internal.h"

static void	writer_unsafe_close(t_writer_count *self)
{
	self->writer->v->unsafe_close(self->writer);
	free(self);
}

static t_err	writer_flush(t_writer_count *self, t_exception **exception)
{
	if (self->writer->v->flush(self->writer, exception))
	{
		if (exception && *exception)
			(*exception)->b->add_stacktrace(
				*exception, __FILE__, __LINE__, NULL);
		return (true);
	}
	return (false);
}

static t_err	writer_write(
	t_writer_count *self,
	const void *buffer,
	size_t len,
	t_exception **exception
)
{
	if (self->writer->v->write(self->writer, buffer, len, exception))
	{
		if (exception && *exception)
			(*exception)->b->add_stacktrace(
				*exception, __FILE__, __LINE__, NULL);
		return (true);
	}
	self->count += len;
	return (false);
}

static const t_writer_vtable	g_v = {
	(t_writer_v_unsafe_close)(&writer_unsafe_close),
	(t_writer_v_write)(&writer_write),
	(t_writer_v_flush)(&writer_flush),
	(t_writer_v_close)(&ft_writer_base_v_default_close)
};

t_writer_count	*new_writer_count(t_writer *writer)
{
	t_writer_count	*result;

	if (!writer)
		return (NULL);
	result = (t_writer_count *) malloc(sizeof(t_writer_count));
	if (!result)
		return (NULL);
	result->base.v = &g_v;
	result->writer = writer;
	result->count = 0;
	return ((t_writer_count *) result);
}
