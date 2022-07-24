/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_exception_methods.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:55:06 by jmaing            #+#    #+#             */
/*   Updated: 2022/07/25 00:28:40 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTO_EXCEPTION_METHODS_H
# define FTO_EXCEPTION_METHODS_H

# include "fto_exception.h"

void		ft_exception_v_free(t_exception *self);
t_err		ft_exception_v_print(t_exception *self, int fd);
const char	*ft_exception_v_getfile(t_exception *self);
int			ft_exception_v_getline(t_exception *self);
t_err		ft_exception_v_add_stacktrace(t_exception *self,
				const char *file,
				int line,
				const char *message);

#endif
