/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 21:07:03 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/19 20:24:05 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H

# include <stddef.h>

typedef enum e_printf_format_length_modifier {
	printf_format_length_modifier_empty,
	printf_format_length_modifier_hh,
	printf_format_length_modifier_h,
	printf_format_length_modifier_l,
	printf_format_length_modifier_ll,
	printf_format_length_modifier_j,
	printf_format_length_modifier_z,
	printf_format_length_modifier_t,
	printf_format_length_modifier_capital_l,
}	t_printf_format_length_modifier;

typedef enum e_printf_format_conversion_specifier {
	printf_format_conversion_specifier_d,
	printf_format_conversion_specifier_i,
	printf_format_conversion_specifier_o,
	printf_format_conversion_specifier_u,
	printf_format_conversion_specifier_x,
	printf_format_conversion_specifier_capital_x,
	printf_format_conversion_specifier_f,
	printf_format_conversion_specifier_capital_f,
	printf_format_conversion_specifier_e,
	printf_format_conversion_specifier_capital_e,
	printf_format_conversion_specifier_g,
	printf_format_conversion_specifier_capital_g,
	printf_format_conversion_specifier_a,
	printf_format_conversion_specifier_capital_a,
	printf_format_conversion_specifier_c,
	printf_format_conversion_specifier_s,
	printf_format_conversion_specifier_p,
	printf_format_conversion_specifier_n,
	printf_format_conversion_specifier_percent,
}	t_printf_format_conversion_specifier;

typedef struct s_printf_format_conversion_specification {
	int										flag_left_justified : 1;
	int										flag_always_show_sign : 1;
	int										flag_use_sign_placeholder : 1;
	int										flag_use_alternative_form : 1;
	int										flag_pad_field_with_zero : 1;
	int										has_minimum_field_width : 1;
	int										has_precision : 1;
	int										variable_minimum_field_width : 1;
	int										variable_precision : 1;
	int										minimum_field_width;
	int										precision;
	t_printf_format_length_modifier			length_modifier;
	t_printf_format_conversion_specifier	conversion_specifier;
}	t_printf_format_conversion_specification;

typedef enum e_printf_format_node_type {
	printf_format_node_type_string,
	printf_format_node_type_conversion_specification,
}	t_printf_format_node_type;

typedef struct s_printf_format_node_union_string {
	t_printf_format_node_type	type;
	const char					*content;
	size_t						length;
}	t_printf_format_node_union_string;

typedef struct s_printf_format_node_union_conversion_specification {
	t_printf_format_node_type					type;
	t_printf_format_conversion_specification	value;
}	t_printf_format_node_union_conversion_specification;

typedef union u_printf_format_node_value {
	void												*any;
	t_printf_format_node_type							*type;
	t_printf_format_node_union_string					*string;
	t_printf_format_node_union_conversion_specification	*conversion;
}	t_printf_format_node_value;

typedef struct s_printf_format_node {
	struct s_printf_format_node	*next;
	t_printf_format_node_value	value;
}	t_printf_format_node;

typedef struct s_printf_format {
	t_printf_format_node	*head;
	t_printf_format_node	*tail;
}	t_printf_format;

t_printf_format	*printf_format_parse(const char *format);
void			printf_format_free(t_printf_format *self);

#endif
