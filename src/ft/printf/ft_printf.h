/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 00:07:24 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/15 17:13:11 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_types.h"

# include "fto_stream_out.h"
# include "fto_va.h"

t_err	ft_printf_v_stream(
			t_fto_stream_out *stream,
			const char *format,
			t_fto_va *va);
t_err	ft_printf_v_as(
			char **out,
			size_t *out_length,
			const char *format,
			t_fto_va *va);
t_err	ft_printf_v_d(
			int fd,
			size_t *out_length,
			const char *format,
			t_fto_va *va);

t_err	ft_printf_stream(
			t_fto_stream_out *stream,
			const char *format,
			...);
t_err	ft_printf_as(
			char **out,
			size_t *out_length,
			const char *format,
			...);
t_err	ft_printf_d(
			int fd,
			size_t *out_length,
			const char *format,
			...);

int		ft_printf(
			const char *format,
			...);

#endif
