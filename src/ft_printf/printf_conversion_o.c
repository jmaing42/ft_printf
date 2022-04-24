/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_o.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:05:31 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/24 14:20:30 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_conversion_o.h"

static t_err	print_nonzero(
	t_ft_vprintf_stream_context *context,
	t_o *layout,
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
		|| ft_vprintf_stream_u_put(context, layout->value, 8, "01234567")
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

t_err	ft_vprintf_stream_o(
	t_ft_vprintf_stream_context *context,
	va_list arguments,
	t_printf_format_conversion_specification *conversion
)
{
	t_o			o;
	const int	mfw = ft_vprintf_get_mfw_actual(arguments, conversion, &o.left);
	const int	precision = ft_vprintf_get_precision(arguments, conversion, -1);

	if (ft_vprintf_get_any_u(arguments, conversion->length_modifier, &o.value))
		return (true);
	if (conversion->flag_use_alternative_form
		|| conversion->flag_always_show_sign
		|| conversion->flag_use_sign_placeholder)
		ft_vprintf_stream_undefined_behavior_hooray();
	if (!o.value)
		return (print_zero(context, conversion, mfw, precision));
	o.length = ft_vprintf_stream_u_length(o.value, 8);
	return (print_nonzero(context, &o, mfw, precision));
}
