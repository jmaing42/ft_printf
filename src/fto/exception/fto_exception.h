/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_exception.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:47:09 by jmaing            #+#    #+#             */
/*   Updated: 2022/07/25 00:30:59 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTO_EXCEPTION_H
# define FTO_EXCEPTION_H

# include <stddef.h>

# include "fto_exception_base.h"

typedef struct s_exception_stacktrace_node
{
	struct s_exception_stacktrace_node	*next;
	const char							*file;
	int									line;
	char								*message;
}	t_exception_stacktrace_node;

typedef const struct s_exception_vtable
{
	t_exception_base_vtable			super;
}	t_exception_vtable;

struct s_exception
{
	union
	{
		t_exception_base_vtable	*b;
		t_exception_vtable		*v;
	};
	const char					*message;
	const char					*file;
	int							line;
	t_exception_stacktrace_node	*stacktrace;
	size_t						stacktrace_skipped_count;
};

t_exception	*new_exception(
				const char *message,
				const char *file,
				int line);

#endif
