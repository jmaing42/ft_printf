/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_fd_in_new.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:10:05 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/25 09:22:24 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_fd_in_v.h"

#include <stdlib.h>

static const struct s_fto_stream_fd_in_vtable	g_v = {
	&fto_stream_fd_in_v_read,
	&fto_stream_fd_in_v_free,
};

t_fto_stream_fd_in	*new_fto_stream_fd_in(int fd, bool fd_owned)
{
	t_fto_stream_fd_in *const	result = malloc(sizeof(t_fto_stream_fd_in));

	if (!result)
		return (NULL);
	result->v->v = &g_v;
	result->fd = fd;
	result->fd_owned = fd_owned;
	return (result);
}
