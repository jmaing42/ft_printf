/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception_methods.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:55:06 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 10:54:42 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXCEPTION_METHODS_H
# define FT_EXCEPTION_METHODS_H

# include "ft_exception.h"

void		ft_exception_v_delete(t_exception *self);
t_err		ft_exception_v_print(t_exception *self, int fd);
const char	*ft_exception_v_getfile(t_exception *self);
int			ft_exception_v_getline(t_exception *self);
t_err		ft_exception_v_add_stacktrace(t_exception *self,
				const char *file,
				int line,
				const char *message);

#endif
