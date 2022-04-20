/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf_stream.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 22:30:55 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/20 17:25:04 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "format.h"
#include "printf.h"

typedef t_printf_format_conversion_specification	t_conversion;
typedef t_err										(*t_processor)(
		const t_ft_printf_stream_class *type,
		void *context,
		va_list arguments,
		t_conversion *value);
typedef struct s_conversion_entry {
	t_printf_format_conversion_specifier	type;
	t_processor								process;
}													t_conversion_entry;

static const t_conversion_entry						g_conversions[] = {
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
	const t_ft_printf_stream_class *stream_class,
	void *context,
	va_list arguments,
	t_printf_format_node *node
)
{
	size_t	i;

	if (*node->value.type == printf_format_node_type_string)
	{
		return (stream_class->writer(
				context,
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
					stream_class,
					context,
					arguments,
					&node->value.conversion->value));
		i++;
	}
	return (false);
}

t_err	ft_vprintf_stream(
	const t_ft_printf_stream stream,
	size_t *out_bytes_wrote,
	const char *format,
	va_list arguments
)
{
	void *const				context = stream.type->init(stream.param);
	t_printf_format *const	list = printf_format_parse(format);
	t_printf_format_node	*node;

	if (!list)
		stream.type->fini(context);
	if (!context)
		printf_format_free(list);
	if (!list || !context)
		return (true);
	node = list->head;
	while (node)
	{
		if (ft_vprintf_stream_node(stream.type, context, arguments, node))
		{
			stream.type->fini(context);
			printf_format_free(list);
			return (true);
		}
		node = node->next;
	}
	*out_bytes_wrote = stream.type->get_bytes_wrote(context);
	stream.type->fini(context);
	printf_format_free(list);
	return (false);
}
