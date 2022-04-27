/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_p.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 08:26:48 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/28 01:36:40 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_conversion_p.h"

#include "../libft/ft_math.h"

static t_err	print(
	t_ft_vprintf_stream_context *context,
	t_p *p
)
{
	const int	zeros = ft_max_d(0, p->precision - p->length);
	const int	space = ft_max_d(0,
			p->minimum_field_width - p->length - zeros - 2);

	return ((!p->left
			&& space
			&& ft_vprintf_stream_util_print_n(context, space, ' '))
		|| context->stream_class->writer(context->stream, "0x", 2)
		|| (zeros
			&& ft_vprintf_stream_util_print_n(context, zeros, '0'))
		|| ft_vprintf_stream_u_put(context, p->value, 16, "0123456789abcdef")
		|| (p->left
			&& space
			&& ft_vprintf_stream_util_print_n(context, space, ' ')));
}

t_err	ft_vprintf_stream_p(
	t_ft_vprintf_stream_context *context,
	va_list arguments,
	t_printf_format_conversion_specification *conversion
)
{
	t_p			p;
	const int	mfw = ft_vprintf_get_mfw_actual(arguments, conversion, &p.left);
	const int	precision = ft_vprintf_get_precision(arguments, conversion, -1);
	void *const	v = ft_vprintf_get_p(arguments);

	p.value = *((uintptr_t *)&v);
	p.length = ft_vprintf_stream_u_length(p.value, 16);
	if (precision == -1)
		p.precision = ft_max_d(p.length, 1);
	else
		p.precision = ft_max_d(p.length, precision);
	if (precision == -1
		&& !conversion->flag_left_justified
		&& conversion->flag_pad_field_with_zero)
		p.precision = ft_max_d(p.precision, mfw);
	p.minimum_field_width = mfw;
	return (print(context, &p));
}
