/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_o.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:05:31 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/26 22:41:05 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_conversion_o.h"

#include "../libft/ft_math.h"

static t_err	with_precision(
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
	va_list arguments,
	t_printf_format_conversion_specification *conversion
)
{
	t_o			o;
	const int	minimum_field_width = ft_vprintf_get_mfw_actual(
			arguments, conversion, &o.left_justified);
	const int	precision = ft_vprintf_get_precision(arguments, conversion, -1);

	if (ft_vprintf_get_any_u(arguments, conversion->length_modifier, &o.value))
		return (true);
	o.length = ft_vprintf_stream_u_length(o.value, 8);
	o.minimum_field_width = minimum_field_width;
	o.precision = ft_max_d(precision,
			!!conversion->flag_pad_field_with_zero * minimum_field_width);
	o.precision = ft_max_d(o.precision, o.length + !!(
				conversion->flag_use_alternative_form && o.value));
	return (with_precision(context, &o));
}
