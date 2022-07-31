/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_u.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:05:31 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 18:41:47 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_conversion_u.h"

#include "ft_math.h"

static t_err	print(
	t_ft_vprintf_stream_context *context,
	t_u *u
)
{
	const int	zeros = ft_max_d(0, u->precision - u->length);
	const int	space = ft_max_d(0, u->minimum_field_width - u->length - zeros);

	return ((!u->left
			&& space
			&& ft_vprintf_stream_util_print_n(context, space, ' '))
		|| (zeros
			&& ft_vprintf_stream_util_print_n(context, zeros, '0'))
		|| ft_vprintf_stream_u_put(context, u->value, 10, "0123456789")
		|| (u->left
			&& space
			&& ft_vprintf_stream_util_print_n(context, space, ' ')));
}

t_err	ft_vprintf_stream_u(
	t_ft_vprintf_stream_context *context,
	va_list *arguments,
	t_printf_format_conversion_specification *conversion
)
{
	t_u			u;
	const int	mfw = ft_vprintf_get_mfw_actual(arguments, conversion, &u.left);
	const int	precision = ft_vprintf_get_precision(arguments, conversion, -1);

	if (ft_vprintf_get_any_u(arguments, conversion->length_modifier, &u.value))
		return (true);
	if (conversion->flag_always_show_sign
		|| conversion->flag_use_sign_placeholder)
		ft_vprintf_stream_undefined_behavior_hooray();
	u.length = ft_vprintf_stream_u_length(u.value, 10);
	if (precision == -1)
		u.precision = ft_max_d(u.length, 1);
	else
		u.precision = ft_max_d(u.length, precision);
	if (precision == -1
		&& !conversion->flag_left_justified
		&& conversion->flag_pad_field_with_zero)
		u.precision = ft_max_d(u.precision, mfw);
	u.minimum_field_width = mfw;
	return (print(context, &u));
}
