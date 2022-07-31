/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_simple.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:12:37 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 18:41:47 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "internal.h"

#include "ft_default.h"
#include "ft_cstring.h"

t_err	ft_vprintf_stream_percent(
	t_ft_vprintf_stream_context *context,
	va_list *arguments,
	t_printf_format_conversion_specification *conversion
)
{
	ft_vprintf_get_mfw_actual(arguments, conversion, NULL);
	ft_vprintf_get_precision(arguments, conversion, -1);
	if (conversion->length_modifier != printf_format_length_modifier_empty
		|| conversion->flag_left_justified
		|| conversion->flag_always_show_sign
		|| conversion->flag_pad_field_with_zero
		|| conversion->flag_use_alternative_form
		|| conversion->flag_use_sign_placeholder
		|| conversion->has_minimum_field_width
		|| conversion->variable_minimum_field_width
		|| conversion->has_precision
		|| conversion->variable_precision)
		ft_vprintf_stream_undefined_behavior_hooray();
	return (context->stream_class->writer(context->stream, "%", 1));
}

#define UNDEFINED_BEHAVIOR_HOORAY_MESSAGE "\nUndefined behavior occurred! xD\n"

void	ft_vprintf_stream_undefined_behavior_hooray(void)
{
	write(
		STDERR_FILENO,
		UNDEFINED_BEHAVIOR_HOORAY_MESSAGE,
		sizeof(UNDEFINED_BEHAVIOR_HOORAY_MESSAGE) - 1
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
		if (context->stream_class->writer(context->stream, &c, 1))
			return (true);
		i++;
	}
	return (false);
}

t_err	ft_vprintf_stream_c(
	t_ft_vprintf_stream_context *c,
	va_list *arguments,
	t_printf_format_conversion_specification *conversion
)
{
	bool		l;
	const int	mfw = ft_vprintf_get_mfw_actual(arguments, conversion, &l);
	const int	precision = ft_vprintf_get_precision(arguments, conversion, 0);
	const char	value = ft_vprintf_get_d(arguments);

	(void) precision;
	if (conversion->flag_always_show_sign
		|| conversion->flag_pad_field_with_zero
		|| conversion->flag_use_alternative_form
		|| conversion->flag_use_sign_placeholder
		|| conversion->has_precision
		|| conversion->variable_precision)
		ft_vprintf_stream_undefined_behavior_hooray();
	return (conversion->length_modifier != printf_format_length_modifier_empty
		|| (mfw > 1 && !l && ft_vprintf_stream_util_print_n(c, mfw - 1, ' '))
		|| c->stream_class->writer(c->stream, &value, 1)
		|| (mfw > 1 && l && ft_vprintf_stream_util_print_n(c, mfw - 1, ' ')));
}

t_err	ft_vprintf_stream_s(
	t_ft_vprintf_stream_context *context,
	va_list *arguments,
	t_printf_format_conversion_specification *conv
)
{
	bool		left;
	const int	mfw = ft_vprintf_get_mfw_actual(arguments, conv, &left);
	const int	precision = ft_vprintf_get_precision(arguments, conv, -1);
	const char	*value;
	size_t		length;

	value = (const char *)ft_vprintf_get_p(arguments);
	if (precision == -1)
		length = ft_strlen((const char *)ft_default_cp(value, "(null)"));
	else
		length = ft_strnlen(
				(const char *)ft_default_cp(value, "(null)"), precision);
	if (!value
		|| conv->flag_always_show_sign
		|| conv->flag_pad_field_with_zero
		|| conv->flag_use_alternative_form
		|| conv->flag_use_sign_placeholder)
		ft_vprintf_stream_undefined_behavior_hooray();
	return (conv->length_modifier != printf_format_length_modifier_empty
		|| ((size_t) mfw > length && !left && ft_vprintf_stream_util_print_n(
				context, mfw - length, ' '))
		|| context->stream_class->writer(context->stream,
			(const char *)ft_default_cp(value, "(null)"), length)
		|| ((size_t) mfw > length && left && ft_vprintf_stream_util_print_n(
				context, mfw - length, ' ')));
}
