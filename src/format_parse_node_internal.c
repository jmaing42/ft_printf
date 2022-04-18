/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parse_node_internal.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:10:03 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/18 23:52:54 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "format_internal.h"

void	printf_format_internal_parse_node_flags(
	const char *format,
	t_printf_format_node_union_conversion_specification *self,
	size_t *out_consumed
)
{
	while (1)
	{
		if (*format == '-')
			self->value.flag_left_justified = 1;
		else if (*format == '+')
			self->value.flag_always_show_sign = 1;
		else if (*format == ' ')
			self->value.flag_use_sign_placeholder = 1;
		else if (*format == '#')
			self->value.flag_use_alternative_form = 1;
		else if (*format == '0')
			self->value.flag_pad_field_with_zero = 1;
		else
			return ;
		format++;
		(*out_consumed)++;
	}
}

bool	printf_format_internal_parse_node_minimum_field_width(
	const char *format,
	t_printf_format_node_union_conversion_specification *self,
	size_t *out_consumed
)
{
	self->value.has_minimum_field_width = 0;
	if (*format == '*')
	{
		self->value.variable_minimum_field_width = 1;
		(*out_consumed)++;
		return (false);
	}
	self->value.variable_minimum_field_width = 0;
	self->value.minimum_field_width = 0;
	while ('0' <= *format && *format <= '9')
	{
		self->value.minimum_field_width
			= self->value.minimum_field_width * 10 + *format - '0';
		if (self->value.minimum_field_width > INT_MAX / 10)
			return (true);
		format++;
		(*out_consumed)++;
		self->value.has_minimum_field_width = 1;
	}
	return (false);
}

bool	printf_format_internal_parse_node_precision(
	const char *format,
	t_printf_format_node_union_conversion_specification *self,
	size_t *out_consumed
)
{
	if (*format != '.')
		return (false);
	format++;
	(*out_consumed)++;
	self->value.has_precision = 0;
	if (*format == '*')
	{
		self->value.variable_precision = 1;
		(*out_consumed)++;
		return (false);
	}
	self->value.variable_precision = 0;
	self->value.precision = 0;
	while ('0' <= *format && *format <= '9')
	{
		self->value.precision = self->value.precision * 10 + *format - '0';
		if (self->value.precision > INT_MAX / 10)
			return (true);
		format++;
		(*out_consumed)++;
		self->value.has_precision = 1;
	}
	return (false);
}

typedef struct s_length_modifier_entry {
	char							key;
	t_printf_format_length_modifier	value;
}	t_length_modifier_entry;

static const t_length_modifier_entry		g_single_char_length_modifiers[] = {
{'h', printf_format_length_modifier_h},
{'l', printf_format_length_modifier_l},
{'j', printf_format_length_modifier_j},
{'z', printf_format_length_modifier_z},
{'t', printf_format_length_modifier_t},
{'L', printf_format_length_modifier_capital_l},
	NULL
};

void	printf_format_internal_parse_node_length_modifier(
	const char *format,
	t_printf_format_node_union_conversion_specification *self,
	size_t *out_consumed
)
{
	const t_length_modifier_entry	*tmp;

	if (*format == *(format + 1) && (*format == 'h' || *format == 'l'))
	{
		self->value.length_modifier = printf_format_length_modifier_ll;
		if (*format == 'h')
			self->value.length_modifier = printf_format_length_modifier_hh;
		*out_consumed += 2;
		return ;
	}
	tmp = g_single_char_length_modifiers;
	while (tmp)
	{
		if (*format == tmp->key)
		{
			self->value.length_modifier = tmp->value;
			(*out_consumed)++;
			return ;
		}
		tmp++;
	}
	self->value.length_modifier = printf_format_length_modifier_empty;
}

typedef struct s_conversion_specifier_entry {
	char									key;
	t_printf_format_conversion_specifier	value;
}	t_conversion_specifier_entry;

static const t_conversion_specifier_entry	g_conversion_specifiers[] = {
{'d', printf_format_conversion_specifier_d},
{'i', printf_format_conversion_specifier_i},
{'o', printf_format_conversion_specifier_o},
{'u', printf_format_conversion_specifier_u},
{'x', printf_format_conversion_specifier_x},
{'X', printf_format_conversion_specifier_capital_x},
{'f', printf_format_conversion_specifier_f},
{'F', printf_format_conversion_specifier_capital_f},
{'e', printf_format_conversion_specifier_e},
{'E', printf_format_conversion_specifier_capital_e},
{'g', printf_format_conversion_specifier_g},
{'G', printf_format_conversion_specifier_capital_g},
{'a', printf_format_conversion_specifier_a},
{'A', printf_format_conversion_specifier_capital_a},
{'c', printf_format_conversion_specifier_c},
{'s', printf_format_conversion_specifier_s},
{'p', printf_format_conversion_specifier_p},
{'n', printf_format_conversion_specifier_n},
{'%', printf_format_conversion_specifier_percent},
	NULL
};

bool	printf_format_internal_parse_node_conversion_specifier(
	const char *format,
	t_printf_format_node_union_conversion_specification *self,
	size_t *out_consumed
)
{
	const t_conversion_specifier_entry	*tmp;

	tmp = g_conversion_specifiers;
	while (tmp)
	{
		if (*format == tmp->key)
		{
			self->value.conversion_specifier = tmp->value;
			(*out_consumed)++;
			return (false);
		}
		tmp++;
	}
	return (true);
}
