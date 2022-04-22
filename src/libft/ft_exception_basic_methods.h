/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception_basic_methods.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:55:06 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 10:05:38 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXCEPTION_BASIC_METHODS_H
# define FT_EXCEPTION_BASIC_METHODS_H

# include "ft_exception_basic.h"

void		ft_exception_basic_v_delete(t_exception_basic *self);
t_err		ft_exception_basic_v_print(t_exception_basic *self, int fd);
const char	*ft_exception_basic_v_getfile(t_exception_basic *self);
int			ft_exception_basic_v_getline(t_exception_basic *self);
t_err		ft_exception_basic_v_add_stacktrace(t_exception_basic *self,
				const char *file,
				int line,
				const char *message);

#endif
