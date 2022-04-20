/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_simple.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:12:37 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/20 21:20:34 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "printf.h"
#include "util.h"

t_err	ft_vprintf_stream_percent(
	t_ft_vprintf_stream_context *context,
	va_list arguments,
	t_printf_format_conversion_specification *conversion
)
{
	(void) arguments;
	(void) conversion;
	return (context->stream_class->writer(context->stream_context, "%", 1));
}

#define UNDEFINED_BEHAVIOR_HORRAY_MESSAGE "\nUndefined behavior occurred! xD\n"

void	ft_vprintf_stream_undefined_behavior_horray(void)
{
	write(
		2,
		UNDEFINED_BEHAVIOR_HORRAY_MESSAGE,
		sizeof(UNDEFINED_BEHAVIOR_HORRAY_MESSAGE) - 1
		);
}

t_err	ft_vprintf_stream_util_print_n(
	t_ft_vprintf_stream_context *context,
	int n,
	char c
)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (context->stream_class->writer(context->stream_context, &c, 1))
			return (true);
		i++;
	}
	return (false);
}

t_err	ft_vprintf_stream_c(
	t_ft_vprintf_stream_context *c,
	va_list arguments,
	t_printf_format_conversion_specification *conversion
)
{
	bool		l;
	const int	mfw = ft_vprintf_get_mfw_actual(arguments, conversion, &l);
	const int	precision = ft_vprintf_get_precision(arguments, conversion, -1);
	const char	value = ft_vprintf_get_d(arguments);

	if (conversion->flag_always_show_sign
		|| conversion->flag_pad_field_with_zero
		|| conversion->flag_use_alternative_form
		|| conversion->flag_use_sign_placeholder
		|| conversion->has_precision
		|| conversion->variable_precision
		|| precision >= 0)
		ft_vprintf_stream_undefined_behavior_horray();
	return ((mfw > 1 && l && ft_vprintf_stream_util_print_n(c, mfw - 1, ' '))
		|| c->stream_class->writer(c->stream_context, &value, 1)
		|| (mfw > 1 && l && ft_vprintf_stream_util_print_n(c, mfw - 1, ' ')));
}

t_err	ft_vprintf_stream_s(
	t_ft_vprintf_stream_context *context,
	va_list args,
	t_printf_format_conversion_specification *conv
)
{
	bool				left;
	const int			mfw = ft_vprintf_get_mfw_actual(args, conv, &left);
	const int			precision = ft_vprintf_get_precision(args, conv, 0);
	const char *const	value = (const char *) ft_vprintf_get_p(args);
	const size_t		length = ft_strnlen(value, precision);

	if (conv->flag_always_show_sign
		|| conv->flag_pad_field_with_zero
		|| conv->flag_use_alternative_form
		|| conv->flag_use_sign_placeholder)
		ft_vprintf_stream_undefined_behavior_horray();
	return (((size_t) mfw > length && left && ft_vprintf_stream_util_print_n(
				context, mfw - length, ' '))
		|| context->stream_class->writer(context->stream_context, value, length)
		|| ((size_t) mfw > length && left && ft_vprintf_stream_util_print_n(
				context, mfw - length, ' ')));
}
