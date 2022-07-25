/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_fd_in.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 08:52:10 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/25 09:05:59 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTO_STREAM_FD_IN_H
# define FTO_STREAM_FD_IN_H

# include "fto_stream_in.h"

# include "ft_types.h"

typedef struct s_fto_stream_fd_in
{
	union u_fto_stream_fd_in_vtable	*v;
	int								fd;
	bool							fd_owned;
}	t_fto_stream_fd_in;

typedef t_err	(*t_fto_stream_fd_in_v_read(
					t_fto_stream_fd_in *self,
					const char *buffer,
					size_t length,
					size_t *read_bytes));
typedef void	(*t_fto_stream_fd_in_v_free(
					t_fto_stream_fd_in *self));

struct s_fto_stream_fd_in_vtable
{
	t_fto_stream_fd_in_v_read	read;
	t_fto_stream_fd_in_v_free	free;
};

typedef union u_fto_stream_fd_in_vtable
{
	struct s_fto_stream_fd_in_vtable	v;
	t_fto_stream_in_vtable				s;
}	t_fto_stream_fd_in_vtable;

t_fto_stream_fd_in	*new_fto_stream_fd_in(int fd, bool fd_owned);

#endif
