/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_string_out.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 08:52:10 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/26 09:15:24 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTO_STREAM_STRING_OUT_H
# define FTO_STREAM_STRING_OUT_H

# include "fto_stream_out.h"

# include "ft_stringbuilder.h"

typedef struct s_fto_stream_string_out
{
	union u_fto_stream_string_out_vtable	*v;
	t_stringbuilder							*stringbuilder;
}	t_fto_stream_string_out;

typedef t_err	(*t_fto_stream_string_out_v_write)(
					t_fto_stream_string_out *self,
					const char *buffer,
					size_t length,
					size_t *wrote_bytes);
typedef t_err	(*t_fto_stream_string_out_v_flush)(
					t_fto_stream_string_out *self);
typedef t_err	(*t_fto_stream_string_out_v_try_free)(
					t_fto_stream_string_out *self);
typedef void	(*t_fto_stream_string_out_v_unsafe_free)(
					t_fto_stream_string_out *self);
typedef char	*(*t_fto_stream_string_out_v_to_string)(
					t_fto_stream_string_out *self);

struct s_fto_stream_string_out_vtable
{
	t_fto_stream_string_out_v_write			write;
	t_fto_stream_string_out_v_flush			flush;
	t_fto_stream_string_out_v_try_free		try_free;
	t_fto_stream_string_out_v_unsafe_free	unsafe_free;
	t_fto_stream_string_out_v_to_string		to_string;
};

typedef union u_fto_stream_string_out_vtable
{
	const struct s_fto_stream_string_out_vtable	*v;
	const t_fto_stream_out_vtable				*s;
}	t_fto_stream_string_out_vtable;

t_fto_stream_string_out	*new_fto_stream_string_out(void);

#endif
