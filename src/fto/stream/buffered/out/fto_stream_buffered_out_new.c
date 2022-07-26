/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_buffered_out_new.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 23:51:16 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/26 23:56:42 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_buffered_out_v.h"

#include <stdlib.h>

static const struct s_fto_stream_buffered_out_vtable	g_v = {
	&fto_stream_buffered_out_v_write,
	&fto_stream_buffered_out_v_flush,
	&fto_stream_buffered_out_v_try_free,
	&fto_stream_buffered_out_v_unsafe_free
};

t_fto_stream_buffered_out	*new_fto_stream_buffered_out(
	t_fto_stream_out *stream,
	bool stream_owned,
	size_t buffer_size
)
{
	t_fto_stream_buffered_out *const	result
		= malloc(sizeof(t_fto_stream_buffered_out) + buffer_size);

	if (!result)
	{
		if (stream_owned)
			stream->v->unsafe_free(stream);
		return (NULL);
	}
	result->v.v = &g_v;
	result->stream = stream;
	result->stream_owned = stream_owned;
	result->buffer_size = buffer_size;
	result->buffer_offset = 0;
	return (result);
}
