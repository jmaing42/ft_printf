/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 22:34:21 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/19 22:41:43 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stddef.h>
# include <inttypes.h>

# include "libftprintf.h"
# include "format.h"

bool	ft_vprintf_stream_d(
			t_ft_printf_stream stream,
			t_printf_format_conversion_specification conversion_specification);
bool	ft_vprintf_stream_i(
			t_ft_printf_stream stream,
			t_printf_format_conversion_specification conversion_specification);
bool	ft_vprintf_stream_o(
			t_ft_printf_stream stream,
			t_printf_format_conversion_specification conversion_specification);
bool	ft_vprintf_stream_u(
			t_ft_printf_stream stream,
			t_printf_format_conversion_specification conversion_specification);
bool	ft_vprintf_stream_x(
			t_ft_printf_stream stream,
			t_printf_format_conversion_specification conversion_specification);
bool	ft_vprintf_stream_capital_x(
			t_ft_printf_stream stream,
			t_printf_format_conversion_specification conversion_specification);
bool	ft_vprintf_stream_f(
			t_ft_printf_stream stream,
			t_printf_format_conversion_specification conversion_specification);
bool	ft_vprintf_stream_capital_f(
			t_ft_printf_stream stream,
			t_printf_format_conversion_specification conversion_specification);
bool	ft_vprintf_stream_e(
			t_ft_printf_stream stream,
			t_printf_format_conversion_specification conversion_specification);
bool	ft_vprintf_stream_capital_E(
			t_ft_printf_stream stream,
			t_printf_format_conversion_specification conversion_specification);
bool	ft_vprintf_stream_g(
			t_ft_printf_stream stream,
			t_printf_format_conversion_specification conversion_specification);
bool	ft_vprintf_stream_capital_g(
			t_ft_printf_stream stream,
			t_printf_format_conversion_specification conversion_specification);
bool	ft_vprintf_stream_a(
			t_ft_printf_stream stream,
			t_printf_format_conversion_specification conversion_specification);
bool	ft_vprintf_stream_capital_a(
			t_ft_printf_stream stream,
			t_printf_format_conversion_specification conversion_specification);
bool	ft_vprintf_stream_c(
			t_ft_printf_stream stream,
			t_printf_format_conversion_specification conversion_specification);
bool	ft_vprintf_stream_s(
			t_ft_printf_stream stream,
			t_printf_format_conversion_specification conversion_specification);
bool	ft_vprintf_stream_p(
			t_ft_printf_stream stream,
			t_printf_format_conversion_specification conversion_specification);
bool	ft_vprintf_stream_n(
			t_ft_printf_stream stream,
			t_printf_format_conversion_specification conversion_specification);
bool	ft_vprintf_stream_percent(
			t_ft_printf_stream stream,
			t_printf_format_conversion_specification conversion_specification);

#endif
