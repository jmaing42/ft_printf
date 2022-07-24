/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_writer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:48:04 by jmaing            #+#    #+#             */
/*   Updated: 2022/07/25 00:35:35 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTO_WRITER_H
# define FTO_WRITER_H

# include "fto_exception.h"

typedef struct s_writer	t_writer;

typedef void			(*t_writer_v_unsafe_close)(
							t_writer *self);
typedef t_err			(*t_writer_v_write)(
							t_writer *self,
							const void *buffer,
							size_t len,
							t_exception **exception);
typedef t_err			(*t_writer_v_flush)(
							t_writer *self,
							t_exception **exception);
typedef t_err			(*t_writer_v_close)(
							t_writer *self,
							t_exception **exception);

typedef struct s_writer_vtable
{
	t_writer_v_unsafe_close		unsafe_close;
	t_writer_v_write			write;
	t_writer_v_flush			flush;
	t_writer_v_close			close;
}	t_writer_vtable;

struct s_writer
{
	const t_writer_vtable	*v;
};

#endif
