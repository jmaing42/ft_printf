/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_d.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:27:56 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/26 22:02:41 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_conversion_d.h"

#include "../libft/ft_math.h"

#include "../libft/ft_math.h"

static t_err	ft_vprintf_stream_d_zero_fill(
	t_ft_vprintf_stream_context *context,
	t_d *d
)
{
	const int	len = ft_vprintf_stream_i_length(d->value, 10) + !!d->sign;
	const int	zeros = d->minimum_field_width - len;

	return (
		(d->sign && context->stream_class->writer(context->stream, &d->sign, 1))
		|| ft_vprintf_stream_util_print_n(context, zeros, '0')
		|| ft_vprintf_stream_i_put(context, d->value, 10, "0123456789")
	);
}

static t_err	ft_vprintf_stream_d_with_precision(
	t_ft_vprintf_stream_context *context,
	t_d *d
)
{
	const int	digits = ft_vprintf_stream_i_length(d->value, 10);
	const int	zeros = ft_max_d(d->precision - digits, 0);
	const int	len = digits + zeros + !!d->sign;
	const int	spaces = ft_max_d(d->minimum_field_width - len, 0);

	return ((!d->left_justified
			&& spaces
			&& ft_vprintf_stream_util_print_n(context, spaces, ' '))
		|| (d->sign
			&& context->stream_class->writer(context->stream, &d->sign, 1))
		|| (zeros
			&& ft_vprintf_stream_util_print_n(context, zeros, '0'))
		|| ft_vprintf_stream_i_put(context, d->value, 10, "0123456789")
		|| (d->left_justified
			&& spaces
			&& ft_vprintf_stream_util_print_n(context, spaces, ' ')));
}

static t_err	ft_vprintf_stream_d_without_precision(
	t_ft_vprintf_stream_context *context,
	t_d *d
)
{
	const int	digits = ft_vprintf_stream_i_length(d->value, 10);
	const int	len = digits + !!d->sign;
	const int	spaces = ft_max_d(d->minimum_field_width - len, 0);

	return ((!d->left_justified
			&& spaces
			&& ft_vprintf_stream_util_print_n(context, spaces, ' '))
		|| (d->sign
			&& context->stream_class->writer(context->stream, &d->sign, 1))
		|| ft_vprintf_stream_i_put(context, d->value, 10, "0123456789")
		|| (d->left_justified
			&& spaces
			&& ft_vprintf_stream_util_print_n(context, spaces, ' ')));
}

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
