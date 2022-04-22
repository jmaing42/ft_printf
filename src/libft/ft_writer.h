/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:48:04 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 13:11:26 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WRITER_H
# define FT_WRITER_H

# include "ft_exception.h"

typedef struct s_writer	t_writer;

typedef void			(*t_writer_v_unsafe_delete)(
							t_writer *self);
typedef t_err			(*t_writer_v_write)(
							t_writer *self,
							const void *buffer,
							size_t len,
							t_exception **exception);
typedef t_err			(*t_writer_v_flush)(
							t_writer *self,
							t_exception **exception);
typedef t_err			(*t_writer_v_delete)(
							t_writer *self,
							t_exception **exception);

typedef struct s_writer_vtable
{
	t_writer_v_unsafe_delete	unsafe_delete;
	t_writer_v_write			write;
	t_writer_v_flush			flush;
	t_writer_v_delete			delete;
}	t_writer_vtable;

struct s_writer {
	t_writer_vtable	*v;
};

#endif
