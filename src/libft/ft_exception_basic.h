/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception_basic.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:47:09 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 06:08:17 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXCEPTION_BASIC_H
# define FT_EXCEPTION_BASIC_H

# include "ft_exception.h"

typedef const struct s_exception_basic_vtable {
	t_exception_vtable	super;
}	t_exception_basic_vtable;

typedef struct s_exception_basic {
	t_exception_basic_vtable	*v;
	const char					*message;
	const char					*file;
	int							line;
}	t_exception_basic;

t_exception_basic	*new_exception(
						const char *message,
						const char *file,
						int line);

#endif
