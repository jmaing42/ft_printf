/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:26:11 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/18 23:52:22 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_INTERNAL_H
# define FORMAT_INTERNAL_H

# include <stdbool.h>

# include "format.h"

/**
 * @brief parse single node
 *
 * @param format starting point of format string
 * @param out_result out parameter to get result
 * @param out_consumed consumed char count from format
 * @return true on error
 * @return false on success
 */
bool	printf_format_internal_parse_node(
			const char *format,
			t_printf_format_node **out_result,
			size_t *out_consumed
			);

void	printf_format_internal_parse_node_flags(
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
void	printf_format_internal_parse_node_length_modifier(
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
