/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_n.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:53:35 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/20 19:07:41 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

#include "printf.h"

t_err	ft_vprintf_stream_n(
	t_ft_vprintf_stream_context *context,
	va_list arguments,
	t_printf_format_conversion_specification *conversion
)
{
	t_ft_vprintf_stream_context_n_list *const	current = context->list;
	t_ft_vprintf_stream_context_n_list *const	node
		= (t_ft_vprintf_stream_context_n_list *) malloc(
			sizeof(t_ft_vprintf_stream_context_n_list));

	if (!node)
		return (true);
	node->next = current;
	node->type = conversion->length_modifier;
	node->value = va_arg(arguments, void *);
	context->list = node;
	return (false);
}

t_err	ft_vprintf_stream_fini_set_n(
	size_t size,
	t_ft_vprintf_stream_context_n_list *node
)
{
	if (node->type == printf_format_length_modifier_empty)
		return (ft_vprintf_stream_fini_set_n_empty(size, node->value));
	if (node->type == printf_format_length_modifier_hh)
		return (ft_vprintf_stream_fini_set_n_hh(size, node->value));
	if (node->type == printf_format_length_modifier_h)
		return (ft_vprintf_stream_fini_set_n_h(size, node->value));
	if (node->type == printf_format_length_modifier_l)
		return (ft_vprintf_stream_fini_set_n_l(size, node->value));
	if (node->type == printf_format_length_modifier_ll)
		return (ft_vprintf_stream_fini_set_n_ll(size, node->value));
	if (node->type == printf_format_length_modifier_j)
		return (ft_vprintf_stream_fini_set_n_j(size, node->value));
	if (node->type == printf_format_length_modifier_z)
		return (ft_vprintf_stream_fini_set_n_z(size, node->value));
	if (node->type == printf_format_length_modifier_t)
		return (ft_vprintf_stream_fini_set_n_t(size, node->value));
	return (false);
}

t_err	ft_vprintf_stream_fini_set_n_j(size_t size, void *n)
{
	if (size > INTMAX_MAX)
		return (false);
	*((intmax_t *) n) = (intmax_t) size;
	return (true);
}

t_err	ft_vprintf_stream_fini_set_n_z(size_t size, void *n)
{
	if (size > SSIZE_MAX)
		return (false);
	*((ssize_t *) n) = (ssize_t) size;
	return (true);
}

t_err	ft_vprintf_stream_fini_set_n_t(size_t size, void *n)
{
	if (size > PTRDIFF_MAX)
		return (false);
	*((ptrdiff_t *) n) = (ptrdiff_t) size;
	return (true);
}
