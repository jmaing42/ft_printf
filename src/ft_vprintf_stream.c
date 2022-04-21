/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf_stream.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 22:30:55 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/21 00:41:56 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_vprintf_stream.h"

static const t_conversion_entry	g_conversions[] = {
{printf_format_conversion_specifier_d, &ft_vprintf_stream_d},
{printf_format_conversion_specifier_i, &ft_vprintf_stream_i},
{printf_format_conversion_specifier_o, &ft_vprintf_stream_o},
{printf_format_conversion_specifier_u, &ft_vprintf_stream_u},
{printf_format_conversion_specifier_x, &ft_vprintf_stream_x},
{printf_format_conversion_specifier_capital_x, &ft_vprintf_stream_capital_x},
{printf_format_conversion_specifier_f, &ft_vprintf_stream_f},
{printf_format_conversion_specifier_capital_f, &ft_vprintf_stream_capital_f},
{printf_format_conversion_specifier_e, &ft_vprintf_stream_e},
{printf_format_conversion_specifier_capital_e, &ft_vprintf_stream_capital_e},
{printf_format_conversion_specifier_g, &ft_vprintf_stream_g},
{printf_format_conversion_specifier_capital_g, &ft_vprintf_stream_capital_g},
{printf_format_conversion_specifier_a, &ft_vprintf_stream_a},
{printf_format_conversion_specifier_capital_a, &ft_vprintf_stream_capital_a},
{printf_format_conversion_specifier_c, &ft_vprintf_stream_c},
{printf_format_conversion_specifier_s, &ft_vprintf_stream_s},
{printf_format_conversion_specifier_p, &ft_vprintf_stream_p},
{printf_format_conversion_specifier_n, &ft_vprintf_stream_n},
{printf_format_conversion_specifier_percent, &ft_vprintf_stream_percent},
};

static t_err	ft_vprintf_stream_node(
	t_ft_vprintf_stream_context *context,
	va_list arguments,
	t_printf_format_node *node
)
{
	size_t	i;

	if (*node->value.type == printf_format_node_type_string)
	{
		return (context->stream_class->writer(
				context->stream_context,
				node->value.string->content,
				node->value.string->length));
	}
	if (*node->value.type != printf_format_node_type_conversion_specification)
		return (false);
	i = 0;
	while (i < sizeof(g_conversions) / sizeof(g_conversions[0]))
	{
		if (g_conversions[i].type
			== node->value.conversion->value.conversion_specifier)
			return (g_conversions[i].process(
					context,
					arguments,
					&node->value.conversion->value));
		i++;
	}
	return (false);
}

static t_err	init_context(
	t_ft_printf_stream stream,
	t_ft_vprintf_stream_context *out_context
)
{
	out_context->stream_context = stream.type->init(stream.param);
	if (!out_context->stream_context)
		return (true);
	out_context->stream_class = stream.type;
	out_context->list = NULL;
	return (false);
}

static t_err	fini_context(
	t_ft_vprintf_stream_context *context,
	size_t *out_len,
	bool skip
)
{
	t_ft_vprintf_stream_context_n_list	*node;
	t_err								err;

	err = false;
	*out_len = context->stream_class->get_bytes_wrote(context->stream_context);
	while (context->list)
	{
		node = context->list->next;
		if (!skip && ft_vprintf_stream_fini_set_n(*out_len, context->list))
			err = true;
		free(context->list);
		context->list = node;
	}
	context->stream_class->fini(context->stream_context);
	return (err);
}

t_err	ft_vprintf_stream(
	const t_ft_printf_stream stream,
	size_t *out_bytes_wrote,
	const char *format,
	va_list arguments
)
{
	t_printf_format *const		list = printf_format_parse(format);
	t_ft_vprintf_stream_context	context;
	t_printf_format_node		*node;
	t_err						err;

	if (!list || init_context(stream, &context))
		return (true);
	err = false;
	node = list->head;
	while (!err && node)
	{
		err = ft_vprintf_stream_node(&context, arguments, node);
		node = node->next;
	}
	if (fini_context(&context, out_bytes_wrote, err))
		err = true;
	printf_format_free(list);
	return (err);
}
