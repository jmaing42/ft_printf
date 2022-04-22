/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_p.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 08:26:48 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 12:59:46 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_conversion_p.h"

static void	init_conversion_specification(
	t_c *mut_conversion_specification,
	bool left,
	int minimum_field_width
)
{
	mut_conversion_specification->conversion_specifier
		= printf_format_conversion_specifier_x;
	mut_conversion_specification->length_modifier
		= printf_format_length_modifier_z;
	mut_conversion_specification->flag_left_justified = 0;
	if (left)
		mut_conversion_specification->flag_left_justified = 1;
	mut_conversion_specification->flag_always_show_sign = 0;
	mut_conversion_specification->flag_use_sign_placeholder = 0;
	mut_conversion_specification->flag_use_alternative_form = 1;
	mut_conversion_specification->flag_pad_field_with_zero = 0;
	mut_conversion_specification->minimum_field_width = minimum_field_width;
	mut_conversion_specification->has_minimum_field_width = 1;
	mut_conversion_specification->variable_minimum_field_width = 0;
	mut_conversion_specification->has_precision = 0;
	mut_conversion_specification->variable_precision = 0;
}

t_err	ft_vprintf_stream_p(
	t_ft_vprintf_stream_context *context,
	va_list arguments,
	t_c *conversion
)
{
	bool		left;
	const int	mfw = ft_vprintf_get_mfw_actual(arguments, conversion, &left);
	const int	precision = ft_vprintf_get_precision(arguments, conversion, -1);
	t_c			conversion_specification;

	(void) precision;
	if (conversion->length_modifier != printf_format_length_modifier_empty
		|| conversion->flag_always_show_sign
		|| conversion->flag_pad_field_with_zero
		|| conversion->flag_use_alternative_form
		|| conversion->flag_use_sign_placeholder
		|| conversion->has_precision
		|| conversion->variable_precision)
		ft_vprintf_stream_undefined_behavior_hooray();
	conversion_specification = *conversion;
	init_conversion_specification(&conversion_specification, left, mfw);
	return (ft_vprintf_stream_x(context, arguments, &conversion_specification));
}
