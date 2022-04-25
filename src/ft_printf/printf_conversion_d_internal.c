/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_d_internal.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:27:56 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/25 21:03:31 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft_math.h"

#include "printf_conversion_d_internal.h"

t_err	ft_vprintf_stream_d_zero_fill(
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

t_err	ft_vprintf_stream_d_with_precision(
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

t_err	ft_vprintf_stream_d_without_precision(
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
