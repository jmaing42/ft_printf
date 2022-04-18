/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:26:11 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/19 05:35:13 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_INTERNAL_H
# define FORMAT_INTERNAL_H

# include <stdbool.h>

# include "format.h"

bool	printf_format_internal_parse_node_flags(
			const char *format,
			t_printf_format_node_union_conversion_specification *self,
			size_t *out_consumed
			);
bool	printf_format_internal_parse_node_minimum_field_width(
			const char *format,
			t_printf_format_node_union_conversion_specification *self,
			size_t *out_consumed
			);
bool	printf_format_internal_parse_node_precision(
			const char *format,
			t_printf_format_node_union_conversion_specification *self,
			size_t *out_consumed
			);
bool	printf_format_internal_parse_node_length_modifier(
			const char *format,
			t_printf_format_node_union_conversion_specification *self,
			size_t *out_consumed
			);
bool	printf_format_internal_parse_node_conversion_specifier(
			const char *format,
			t_printf_format_node_union_conversion_specification *self,
			size_t *out_consumed
			);

#endif
