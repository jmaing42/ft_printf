/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 05:14:27 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 06:02:21 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXCEPTION_H
# define FT_EXCEPTION_H

typedef struct s_exception	t_exception;

typedef void				(*t_exception_v_delete)(t_exception *self);
typedef void				(*t_exception_v_print)(t_exception *self, int fd);

typedef const struct s_exception_vtable {
	t_exception_v_delete	delete;
	t_exception_v_print		print;
}	t_exception_vtable;

struct s_exception {
	t_exception_vtable	*v;
};

#endif
