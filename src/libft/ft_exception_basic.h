/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception_basic.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:47:09 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 10:09:43 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXCEPTION_BASIC_H
# define FT_EXCEPTION_BASIC_H

# include <stddef.h>

# include "ft_exception.h"

typedef struct s_exception_basic_stacktrace_node {
	struct s_exception_basic_stacktrace_node	*next;
	const char									*file;
	int											line;
	char										*message;
}	t_exception_basic_stacktrace_node;

typedef struct s_exception_basic	t_exception_basic;

typedef char						*(*t_exception_basic_v_getfile)(
										t_exception_basic *self);
typedef int							(*t_exception_basic_v_getline)(
										t_exception_basic *self);
typedef t_err						(*t_exception_basic_v_add_stacktrace)(
										t_exception_basic *self,
										const char *file,
										int line,
										const char *message);

typedef const struct s_exception_basic_vtable {
	t_exception_vtable					super;
	t_exception_basic_v_getfile			getfile;
	t_exception_basic_v_getline			getline;
	t_exception_basic_v_add_stacktrace	add_stacktrace;
}	t_exception_basic_vtable;

struct s_exception_basic {
	union {
		t_exception_vtable			*s;
		t_exception_basic_vtable	*v;
	};
	const char							*message;
	const char							*file;
	int									line;
	t_exception_basic_stacktrace_node	*stacktrace;
	size_t								stacktrace_skipped_count;
};

t_exception_basic	*new_exception(
						const char *message,
						const char *file,
						int line);

#endif
