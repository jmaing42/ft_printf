/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:37:27 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/19 05:35:38 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "format_internal.h"

typedef t_printf_format_node	t_node;

static bool	printf_format_internal_parse_node_string(
	const char *format,
	t_printf_format_node_union_string **out_result,
	size_t *out_consumed
)
{
	t_printf_format_node_union_string	*result;
	size_t								length;

	result = (t_printf_format_node_union_string *) malloc(
			sizeof(t_printf_format_node_union_string));
	if (!result)
		return (true);
	result->type = printf_format_node_type_string;
	result->content = format;
	length = 0;
	while (*format && *format != '%')
	{
		format++;
		length++;
	}
	result->length = length;
	*out_result = result;
	*out_consumed = length;
	return (false);
}

static bool	printf_format_internal_parse_node_conversion_specification(
	const char *format,
	t_printf_format_node_union_conversion_specification **out_result,
	size_t *out_consumed
)
{
	t_printf_format_node_union_conversion_specification	*result;
	size_t												consumed;

	result = (t_printf_format_node_union_conversion_specification *) malloc(
			sizeof(t_printf_format_node_union_conversion_specification));
	consumed = 0;
	if (!result
		|| printf_format_internal_parse_node_flags(
			format + consumed, result, &consumed)
		|| printf_format_internal_parse_node_minimum_field_width(
			format + consumed, result, &consumed)
		|| printf_format_internal_parse_node_minimum_field_width(
			format + consumed, result, &consumed)
		|| printf_format_internal_parse_node_minimum_field_width(
			format + consumed, result, &consumed)
		|| printf_format_internal_parse_node_precision(
			format + consumed, result, &consumed))
	{
		free (result);
		return (true);
	}
	result->type = printf_format_node_type_conversion_specification;
	*out_result = result;
	*out_consumed = consumed;
	return (false);
}

static bool	printf_format_parse_node(
	const char *format,
	t_printf_format_node **out_result,
	size_t *out_consumed
)
{
	if (*format != '%')
	{
		return (
			printf_format_internal_parse_node_string(
				format,
				(t_printf_format_node_union_string **) out_result,
				out_consumed
			)
		);
	}
	return (
		printf_format_internal_parse_node_conversion_specification(
			format,
			(t_printf_format_node_union_conversion_specification **) out_result,
			out_consumed
		)
	);
}

t_printf_format	*printf_format_parse(char *format)
{
	t_printf_format *const	result = (t_printf_format *) malloc(
			sizeof(t_printf_format));
	size_t					consumed;
	t_printf_format_node	*node;

	if (!result)
		return (NULL);
	result->head = NULL;
	result->tail = NULL;
	while (*format && !printf_format_parse_node(format, &node, &consumed))
	{
		format += consumed;
		if (!result->head)
		{
			result->head = node;
			result->tail = node;
			continue ;
		}
		result->tail->next = node;
		result->tail = node;
	}
	if (!*format)
		return (result);
	printf_format_free(result);
	return (NULL);
}

void	printf_format_free(t_printf_format *self)
{
	t_printf_format_node	*node;

	while (self->head)
	{
		node = self->head;
		self->head = node->next;
		free(node);
	}
	free(self);
}
