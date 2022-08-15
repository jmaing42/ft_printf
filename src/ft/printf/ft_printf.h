/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 00:07:24 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/15 19:49:51 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_types.h"

# include "fto_stream_out.h"
# include "fto_va.h"

t_err	ft_printf_va_stream(
			t_fto_stream_out *stream,
			const char *format,
			t_fto_va *va);
t_err	ft_printf_va_string(
			char **out,
			size_t *out_length,
			const char *format,
			t_fto_va *va);
t_err	ft_printf_va_fd(
			int fd,
			size_t *out_length,
			const char *format,
			t_fto_va *va);

int		ft_printf(
			const char *format,
			...);

#endif
