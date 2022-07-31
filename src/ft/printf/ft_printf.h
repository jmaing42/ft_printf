/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 00:07:24 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/01 00:19:59 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_types.h"

# include "fto_va.h"

t_err	ft_printf_v_as(char **out, const char *format, t_fto_va *va);
t_err	ft_printf_v_d(int fd, const char *format, t_fto_va *va);
t_err	ft_printf_as(char **out, const char *format, ...);
t_err	ft_printf_d(int fd, const char *format, ...);
int		ft_printf(const char *format, ...);

#endif
