/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_d.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:27:56 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/25 21:53:29 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_conversion_d_internal.h"

#include "../libft/ft_math.h"

t_err	ft_vprintf_stream_d(
	t_ft_vprintf_stream_context *context,
	va_list a,
	t_printf_format_conversion_specification *c
)
{
	t_d			d;
	const int	minimum_field_width = ft_vprintf_get_mfw_actual(
			a, c, &d.left_justified);
	const int	precision = ft_vprintf_get_precision(a, c, -1);

	if (ft_vprintf_get_any_d(a, c->length_modifier, &d.value))
		return (true);
	if (c->flag_use_alternative_form)
		ft_vprintf_stream_undefined_behavior_hooray();
	d.minimum_field_width = minimum_field_width;
	d.precision = precision;
	d.sign = 0;
	if (d.value < 0)
		d.sign = '-';
	else if (c->flag_always_show_sign)
		d.sign = '+';
	else if (c->flag_use_sign_placeholder)
		d.sign = ' ';
	if (precision == -1
		&& !c->flag_left_justified
		&& c->flag_pad_field_with_zero)
		return (ft_vprintf_stream_d_zero_fill(context, &d));
	if (precision == -1)
		return (ft_vprintf_stream_d_without_precision(context, &d));
	return (ft_vprintf_stream_d_with_precision(context, &d));
}
