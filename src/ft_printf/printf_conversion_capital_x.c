/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_capital_x.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:05:31 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/24 15:24:33 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_conversion_capital_x.h"

static t_err	print_nonzero(
	t_ft_vprintf_stream_context *context,
	t_capital_x *layout,
	int minimum_field_width,
	int precision
)
{
	int	space_padding;
	int	zero_padding;

	zero_padding = precision - layout->length;
	if (zero_padding < 0)
		zero_padding = 0;
	space_padding = minimum_field_width - (layout->length + zero_padding);
	if (space_padding < 0)
		space_padding = 0;
	return ((!layout->left
			&& space_padding
			&& ft_vprintf_stream_util_print_n(context, space_padding, ' '))
		|| (zero_padding
			&& ft_vprintf_stream_util_print_n(context, zero_padding, '0'))
		|| ft_vprintf_stream_u_put(
			context, layout->value, 16, "0123456789ABCDEF")
		|| (layout->left
			&& space_padding
			&& ft_vprintf_stream_util_print_n(context, space_padding, ' ')));
}

static t_err	print_zero(
	t_ft_vprintf_stream_context *context,
	t_printf_format_conversion_specification *conversion,
	int minimum_field_width,
	int precision
)
{
	int	remain;

	if (precision == -1)
		precision = 1;
	remain = minimum_field_width - precision;
	return ((!conversion->flag_left_justified
			&& remain > 0
			&& ft_vprintf_stream_util_print_n(context, remain, ' '))
		|| ft_vprintf_stream_util_print_n(context, precision, '0')
		|| (conversion->flag_left_justified
			&& remain > 0
			&& ft_vprintf_stream_util_print_n(context, remain, ' ')));
}

t_err	ft_vprintf_stream_capital_x(
	t_ft_vprintf_stream_context *context,
	va_list arguments,
	t_printf_format_conversion_specification *conversion
)
{
	t_capital_x	x;
	const int	mfw = ft_vprintf_get_mfw_actual(arguments, conversion, &x.left);
	const int	precision = ft_vprintf_get_precision(arguments, conversion, -1);

	if (ft_vprintf_get_any_u(arguments, conversion->length_modifier, &x.value))
		return (true);
	if (conversion->flag_always_show_sign
		|| conversion->flag_use_sign_placeholder)
		ft_vprintf_stream_undefined_behavior_hooray();
	if (!x.value)
		return (print_zero(context, conversion, mfw, precision));
	x.length = ft_vprintf_stream_u_length(x.value, 16);
	return (print_nonzero(context, &x, mfw, precision));
}
