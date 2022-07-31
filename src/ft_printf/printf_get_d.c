/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_get_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:47:43 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 15:33:19 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

intmax_t	ft_vprintf_get_d(va_list *arguments)
{
	return ((intmax_t) va_arg(*arguments, int));
}

int	ft_vprintf_get_mfw_actual(
	va_list *arguments,
	t_printf_format_conversion_specification *conversion,
	bool *out_flag_left_justified
)
{
	int	result;

	if (out_flag_left_justified)
		*out_flag_left_justified = conversion->flag_left_justified;
	if (conversion->variable_minimum_field_width)
	{
		result = va_arg(*arguments, int);
		if (result < 0)
		{
			result = -result;
			if (out_flag_left_justified)
				*out_flag_left_justified = true;
		}
		return (result);
	}
	else if (conversion->has_minimum_field_width)
		return (conversion->minimum_field_width);
	return (0);
}

int	ft_vprintf_get_precision(
	va_list *arguments,
	t_printf_format_conversion_specification *conversion,
	int fallback
)
{
	int	result;

	if (conversion->variable_precision)
	{
		result = va_arg(*arguments, int);
		if (result >= 0)
			return (result);
	}
	if (conversion->has_precision)
		return (conversion->precision);
	return (fallback);
}
