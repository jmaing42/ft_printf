/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception_base.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 05:14:27 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/26 23:03:05 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXCEPTION_BASE_H
# define FT_EXCEPTION_BASE_H

# include "ft_types.h"

typedef struct s_exception	t_exception;

typedef void				(*t_exception_base_v_free)(
								t_exception *self);
typedef t_err				(*t_exception_base_v_print)(
								t_exception *self,
								int fd);
typedef char				*(*t_exception_base_v_getfile)(
								t_exception *self);
typedef int					(*t_exception_base_v_getline)(
								t_exception *self);
typedef t_err				(*t_exception_base_v_add_stacktrace)(
								t_exception *self,
								const char *file,
								int line,
								const char *message);

typedef const struct s_exception_base_vtable {
	t_exception_base_v_free				free;
	t_exception_base_v_print			print;
	t_exception_base_v_getfile			getfile;
	t_exception_base_v_getline			getline;
	t_exception_base_v_add_stacktrace	add_stacktrace;
}	t_exception_base_vtable;

struct s_exception_base {
	t_exception_base_vtable	*v;
};

#endif
