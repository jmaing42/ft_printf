/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_x.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:05:31 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 18:41:47 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_conversion_x.h"

#include "ft_math.h"

static t_err	print(
	t_ft_vprintf_stream_context *context,
	t_x *x
)
{
	const int	zeros = ft_max_d(0, x->precision - x->length);
	const int	space = ft_max_d(0,
			x->minimum_field_width - x->length - zeros - !!x->prefix * 2);

	return ((!x->left
			&& space
			&& ft_vprintf_stream_util_print_n(context, space, ' '))
		|| (x->prefix
			&& context->stream_class->writer(context->stream, "0x", 2))
		|| (zeros
			&& ft_vprintf_stream_util_print_n(context, zeros, '0'))
		|| ft_vprintf_stream_u_put(context, x->value, 16, "0123456789abcdef")
		|| (x->left
			&& space
			&& ft_vprintf_stream_util_print_n(context, space, ' ')));
}

t_err	ft_vprintf_stream_x(
	t_ft_vprintf_stream_context *context,
	va_list *arguments,
	t_printf_format_conversion_specification *conversion
)
{
	t_x			x;
	const int	mfw = ft_vprintf_get_mfw_actual(arguments, conversion, &x.left);
	const int	precision = ft_vprintf_get_precision(arguments, conversion, -1);

	if (ft_vprintf_get_any_u(arguments, conversion->length_modifier, &x.value))
		return (true);
	if (conversion->flag_always_show_sign
		|| conversion->flag_use_sign_placeholder)
		ft_vprintf_stream_undefined_behavior_hooray();
	x.length = ft_vprintf_stream_u_length(x.value, 16);
	if (precision == -1)
		x.precision = ft_max_d(x.length, 1);
	else
		x.precision = ft_max_d(x.length, precision);
	if (precision == -1
		&& !conversion->flag_left_justified
		&& conversion->flag_pad_field_with_zero)
		x.precision = ft_max_d(x.precision, mfw);
	x.minimum_field_width = mfw;
	x.prefix = (x.length && conversion->flag_use_alternative_form);
	return (print(context, &x));
}
