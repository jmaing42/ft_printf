/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_unwinder_list.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:05:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/02 00:29:56 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTO_UNWINDER_LIST_H
# define FTO_UNWINDER_LIST_H

# include "fto_unwinder.h"

# include <stdbool.h>

union u_fto_unwinder_list_vtable
{
	const struct s_fto_unwinder_list_vtable	*v;
	const t_fto_unwinder_vtable				*s;
};

typedef struct s_fto_unwinder_list_node
{
	struct s_fto_unwinder_list_node	*next;
	void							*value;
	void							(*how_to_remove_value)(void *value);
	void							**destination;
	bool							remove_always;
}	t_fto_unwinder_list_node;

typedef struct s_fto_unwinder_list
{
	union u_fto_unwinder_list_vtable	v;
	t_fto_unwinder_list_node			*head;
}	t_fto_unwinder_list;

typedef t_err	(*t_fto_unwinder_list_v_end_ok)(
					t_fto_unwinder_list *self);
typedef t_err	(*t_fto_unwinder_list_v_end_error)(
					t_fto_unwinder_list *self);
typedef t_err	(*t_fto_unwinder_list_v_add)(
					t_fto_unwinder_list *self,
					void **destination,
					void *value,
					void (*how_to_remove_value)(void *value));
typedef t_err	(*t_fto_unwinder_list_v_add_always)(
					t_fto_unwinder_list *self,
					void **destination,
					void *value,
					void (*how_to_remove_value)(void *value));

typedef struct s_fto_unwinder_list_vtable
{
	t_fto_unwinder_list_v_end_ok		end_ok;
	t_fto_unwinder_list_v_end_error		end_error;
	t_fto_unwinder_list_v_add			add;
	t_fto_unwinder_list_v_add_always	add_always;
}	t_fto_unwinder_list_vtable;

t_fto_unwinder_list	*new_fto_unwinder_list(void);

#endif
