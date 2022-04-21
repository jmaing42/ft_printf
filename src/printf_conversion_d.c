/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_d.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:27:56 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/21 01:12:18 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_conversion_d.h"

static t_err	print_nonzero(
	t_ft_vprintf_stream_context *context,
	t_d *layout,
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
		|| (layout->sign
			&& context->stream_class->writer(
				context->stream_context, &layout->sign, 1))
		|| (zero_padding
			&& ft_vprintf_stream_util_print_n(context, zero_padding, '0'))
		|| ft_vprintf_stream_i_put(context, layout->value, 10, "0123456789")
		|| (!layout->left
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
	if (conversion->flag_always_show_sign
		|| conversion->flag_use_sign_placeholder)
		remain--;
	return ((!conversion->flag_left_justified
			&& remain > 0
			&& ft_vprintf_stream_util_print_n(context, remain, ' '))
		|| (conversion->flag_always_show_sign
			&& context->stream_class->writer(
				context->stream_context, "+", 1))
		|| (conversion->flag_use_sign_placeholder
			&& context->stream_class->writer(
				context->stream_context, " ", 1))
		|| ft_vprintf_stream_util_print_n(context, precision, '0')
		|| (conversion->flag_left_justified
			&& remain > 0
			&& ft_vprintf_stream_util_print_n(context, remain, ' ')));
}

t_err	ft_vprintf_stream_d(
	t_ft_vprintf_stream_context *context,
	va_list arguments,
	t_printf_format_conversion_specification *conversion
)
{
	t_d			d;
	const int	mfw = ft_vprintf_get_mfw_actual(arguments, conversion, &d.left);
	const int	precision = ft_vprintf_get_precision(arguments, conversion, -1);

	if (ft_vprintf_get_any_d(arguments, conversion->length_modifier, &d.value))
		return (true);
	if (conversion->flag_use_alternative_form)
		ft_vprintf_stream_undefined_behavior_hooray();
	if (!d.value)
		return (print_zero(context, conversion, mfw, precision));
	d.length = ft_vprintf_stream_i_length(d.value, 10) + 1;
	d.sign = 0;
	if (d.value < 0)
		d.sign = '-';
	else if (conversion->flag_use_sign_placeholder)
		d.sign = ' ';
	else if (conversion->flag_always_show_sign)
		d.sign = '+';
	else
		d.length--;
	return (print_nonzero(context, &d, mfw, precision));
}
