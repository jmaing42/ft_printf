/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_o.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:05:31 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/17 19:29:33 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_conversion_o.h"

#include "../libft/ft_math.h"

static t_err	print(
	t_ft_vprintf_stream_context *context,
	t_o *o
)
{
	const int	zeros = ft_max_d(o->precision - o->length, 0);
	const int	space = ft_max_d(o->minimum_field_width - o->length - zeros, 0);

	return ((!o->left_justified
			&& space
			&& ft_vprintf_stream_util_print_n(context, space, ' '))
		|| (zeros
			&& ft_vprintf_stream_util_print_n(context, zeros, '0'))
		|| ft_vprintf_stream_u_put(context, o->value, 8, "01234567")
		|| (o->left_justified
			&& space
			&& ft_vprintf_stream_util_print_n(context, space, ' ')));
}

t_err	ft_vprintf_stream_o(
	t_ft_vprintf_stream_context *context,
	va_list *arguments,
	t_printf_format_conversion_specification *conversion
)
{
	t_o			o;
	const int	minimum_field_width = ft_vprintf_get_mfw_actual(
			arguments, conversion, &o.left_justified);
	const int	precision = ft_vprintf_get_precision(arguments, conversion, -1);

	if (ft_vprintf_get_any_u(arguments, conversion->length_modifier, &o.value))
		return (true);
	if (conversion->flag_always_show_sign
		|| conversion->flag_use_sign_placeholder)
		ft_vprintf_stream_undefined_behavior_hooray();
	o.length = ft_vprintf_stream_u_length(o.value, 8);
	o.minimum_field_width = minimum_field_width;
	if (precision == -1)
		o.precision = ft_max_d(1, o.length);
	else
		o.precision = ft_max_d(precision, o.length);
	if (precision == -1
		&& !conversion->flag_left_justified
		&& conversion->flag_pad_field_with_zero)
		o.precision = ft_max_d(o.precision, minimum_field_width);
	if (conversion->flag_use_alternative_form && o.precision == o.length)
		o.precision++;
	return (print(context, &o));
}
