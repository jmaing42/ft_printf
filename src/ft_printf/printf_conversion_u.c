/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_u.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:05:31 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/26 21:17:29 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_conversion_common.h"

#include "../libft/ft_math.h"

t_err	ft_vprintf_stream_u(
	t_ft_vprintf_stream_context *context,
	va_list arguments,
	t_printf_format_conversion_specification *conversion
)
{
	uintmax_t	value;
	bool		left;
	const int	mfw = ft_vprintf_get_mfw_actual(arguments, conversion, &left);
	int			precision;
	int			length;

	precision = ft_vprintf_get_precision(arguments, conversion, -1);
	if (ft_vprintf_get_any_u(arguments, conversion->length_modifier, &value))
		return (true);
	if (conversion->flag_use_alternative_form
		|| conversion->flag_always_show_sign
		|| conversion->flag_use_sign_placeholder)
		ft_vprintf_stream_undefined_behavior_hooray();
	length = ft_vprintf_stream_u_length(value, 10);
	precision = ft_max_d(precision, length);
	return ((!left && ft_max_d(0, mfw - precision)
			&& ft_vprintf_stream_util_print_n(
				context, ft_max_d(0, mfw - precision), ' '))
		|| (ft_max_d(0, precision - length)
			&& ft_vprintf_stream_util_print_n(
				context, ft_max_d(0, precision - length), '0'))
		|| ft_vprintf_stream_u_put(context, value, 10, "0123456789")
		|| (left && ft_max_d(0, mfw - precision)
			&& ft_vprintf_stream_util_print_n(
				context, ft_max_d(0, mfw - precision), ' ')));
}
