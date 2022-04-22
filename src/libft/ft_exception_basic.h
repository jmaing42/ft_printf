/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception_basic.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:47:09 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 08:22:46 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXCEPTION_BASIC_H
# define FT_EXCEPTION_BASIC_H

# include "ft_exception.h"

typedef struct s_exception_basic	t_exception_basic;

typedef char						*(*t_exception_basic_v_getfile)(
										t_exception_basic *self);
typedef int							(*t_exception_basic_v_getline)(
										t_exception_basic *self);

typedef const struct s_exception_basic_vtable {
	t_exception_vtable			super;
	t_exception_basic_v_getfile	getfile;
	t_exception_basic_v_getline	getline;
}	t_exception_basic_vtable;

struct s_exception_basic {
	union {
		t_exception_vtable			*s;
		t_exception_basic_vtable	*v;
	};
	const char					*message;
	const char					*file;
	int							line;
};

t_exception_basic	*new_exception(
						const char *message,
						const char *file,
						int line);

#endif
