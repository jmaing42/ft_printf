/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:26:11 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 07:49:25 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_INTERNAL_H
# define FORMAT_INTERNAL_H

# include "format.h"

# include "../libft/ft_types.h"

t_err	printf_format_internal_parse_node_flags(
			const char *format,
			t_printf_format_node_union_conversion_specification *self,
			size_t *out_consumed
			);
t_err	printf_format_internal_parse_node_minimum_field_width(
			const char *format,
			t_printf_format_node_union_conversion_specification *self,
			size_t *out_consumed
			);
t_err	printf_format_internal_parse_node_precision(
			const char *format,
			t_printf_format_node_union_conversion_specification *self,
			size_t *out_consumed
			);
t_err	printf_format_internal_parse_node_length_modifier(
			const char *format,
			t_printf_format_node_union_conversion_specification *self,
			size_t *out_consumed
			);
t_err	printf_format_internal_parse_node_conversion_specifier(
			const char *format,
			t_printf_format_node_union_conversion_specification *self,
			size_t *out_consumed
			);

typedef struct s_length_modifier_entry {
	char							key;
	t_printf_format_length_modifier	value;
}	t_length_modifier_entry;

typedef struct s_conversion_specifier_entry {
	char									key;
	t_printf_format_conversion_specifier	value;
}	t_conversion_specifier_entry;

#endif
