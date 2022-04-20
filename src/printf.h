/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 22:34:21 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/20 15:21:24 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stddef.h>
# include <stdint.h>
# include <stdarg.h>

# include "libftprintf.h"
# include "format.h"

intmax_t		ft_vprintf_get_d(va_list arguments);
intmax_t		ft_vprintf_get_ld(va_list arguments);
intmax_t		ft_vprintf_get_lld(va_list arguments);
intmax_t		ft_vprintf_get_jd(va_list arguments);
intmax_t		ft_vprintf_get_zd(va_list arguments);
intmax_t		ft_vprintf_get_td(va_list arguments);
uintmax_t		ft_vprintf_get_u(va_list arguments);
uintmax_t		ft_vprintf_get_lu(va_list arguments);
uintmax_t		ft_vprintf_get_llu(va_list arguments);
uintmax_t		ft_vprintf_get_ju(va_list arguments);
uintmax_t		ft_vprintf_get_zu(va_list arguments);
void			*ft_vprintf_get_p(va_list arguments);
long double		ft_vprintf_get_double(va_list arguments);
long double		ft_vprintf_get_long_double(va_list arguments);
t_err			ft_vprintf_get_any_d(
					va_list arguments,
					t_printf_format_length_modifier length,
					intmax_t *out_result);
t_err			ft_vprintf_get_any_u(
					va_list arguments,
					t_printf_format_length_modifier length,
					uintmax_t *out_result);
t_err			ft_vprintf_get_any_f(
					va_list arguments,
					t_printf_format_length_modifier length,
					long double *out_result);

t_err			ft_vprintf_stream_d(
					t_ft_printf_stream stream,
					va_list arguments,
					t_printf_format_conversion_specification conversion);
t_err			ft_vprintf_stream_i(
					t_ft_printf_stream stream,
					va_list arguments,
					t_printf_format_conversion_specification conversion);
t_err			ft_vprintf_stream_o(
					t_ft_printf_stream stream,
					va_list arguments,
					t_printf_format_conversion_specification conversion);
t_err			ft_vprintf_stream_u(
					t_ft_printf_stream stream,
					va_list arguments,
					t_printf_format_conversion_specification conversion);
t_err			ft_vprintf_stream_x(
					t_ft_printf_stream stream,
					va_list arguments,
					t_printf_format_conversion_specification conversion);
t_err			ft_vprintf_stream_capital_x(
					t_ft_printf_stream stream,
					va_list arguments,
					t_printf_format_conversion_specification conversion);
t_err			ft_vprintf_stream_f(
					t_ft_printf_stream stream,
					va_list arguments,
					t_printf_format_conversion_specification conversion);
t_err			ft_vprintf_stream_capital_f(
					t_ft_printf_stream stream,
					va_list arguments,
					t_printf_format_conversion_specification conversion);
t_err			ft_vprintf_stream_e(
					t_ft_printf_stream stream,
					va_list arguments,
					t_printf_format_conversion_specification conversion);
t_err			ft_vprintf_stream_capital_E(
					t_ft_printf_stream stream,
					va_list arguments,
					t_printf_format_conversion_specification conversion);
t_err			ft_vprintf_stream_g(
					t_ft_printf_stream stream,
					va_list arguments,
					t_printf_format_conversion_specification conversion);
t_err			ft_vprintf_stream_capital_g(
					t_ft_printf_stream stream,
					va_list arguments,
					t_printf_format_conversion_specification conversion);
t_err			ft_vprintf_stream_a(
					t_ft_printf_stream stream,
					va_list arguments,
					t_printf_format_conversion_specification conversion);
t_err			ft_vprintf_stream_capital_a(
					t_ft_printf_stream stream,
					va_list arguments,
					t_printf_format_conversion_specification conversion);
t_err			ft_vprintf_stream_c(
					t_ft_printf_stream stream,
					va_list arguments,
					t_printf_format_conversion_specification conversion);
t_err			ft_vprintf_stream_s(
					t_ft_printf_stream stream,
					va_list arguments,
					t_printf_format_conversion_specification conversion);
t_err			ft_vprintf_stream_p(
					t_ft_printf_stream stream,
					va_list arguments,
					t_printf_format_conversion_specification conversion);
t_err			ft_vprintf_stream_n(
					t_ft_printf_stream stream,
					va_list arguments,
					t_printf_format_conversion_specification conversion);
t_err			ft_vprintf_stream_percent(
					t_ft_printf_stream stream,
					va_list arguments,
					t_printf_format_conversion_specification conversion);

#endif
