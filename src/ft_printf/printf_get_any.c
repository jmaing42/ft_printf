/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_get_any.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:47:43 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 15:33:19 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

t_err	ft_vprintf_get_any_d(
	va_list *arguments,
	t_printf_format_length_modifier length,
	intmax_t *out_result
)
{
	if (length == printf_format_length_modifier_empty
		|| length == printf_format_length_modifier_hh
		|| length == printf_format_length_modifier_h)
		*out_result = ft_vprintf_get_d(arguments);
	else if (length == printf_format_length_modifier_l)
		*out_result = ft_vprintf_get_ld(arguments);
	else if (length == printf_format_length_modifier_ll)
		*out_result = ft_vprintf_get_lld(arguments);
	else if (length == printf_format_length_modifier_j)
		*out_result = ft_vprintf_get_jd(arguments);
	else if (length == printf_format_length_modifier_z)
		*out_result = ft_vprintf_get_zd(arguments);
	else if (length == printf_format_length_modifier_t)
		*out_result = ft_vprintf_get_td(arguments);
	else
		return (true);
	return (false);
}

t_err	ft_vprintf_get_any_u(
	va_list *arguments,
	t_printf_format_length_modifier length,
	uintmax_t *out_result
)
{
	if (length == printf_format_length_modifier_empty
		|| length == printf_format_length_modifier_hh
		|| length == printf_format_length_modifier_h)
		*out_result = ft_vprintf_get_u(arguments);
	else if (length == printf_format_length_modifier_l)
		*out_result = ft_vprintf_get_lu(arguments);
	else if (length == printf_format_length_modifier_ll)
		*out_result = ft_vprintf_get_llu(arguments);
	else if (length == printf_format_length_modifier_j)
		*out_result = ft_vprintf_get_ju(arguments);
	else if (length == printf_format_length_modifier_z)
		*out_result = ft_vprintf_get_zu(arguments);
	else
		return (true);
	return (false);
}

t_err	ft_vprintf_get_any_f(
	va_list *arguments,
	t_printf_format_length_modifier length,
	long double *out_result
)
{
	if (length == printf_format_length_modifier_empty
		|| length == printf_format_length_modifier_l)
		*out_result = ft_vprintf_get_double(arguments);
	else if (length == printf_format_length_modifier_capital_l)
		*out_result = ft_vprintf_get_long_double(arguments);
	else
		return (true);
	return (false);
}
