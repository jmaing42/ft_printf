/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:42:53 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/26 22:15:29 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

#include "ft_printf.h"

#include "../libft/ft_writer_fd.h"
#include "../libft/ft_writer_buffered.h"

static t_err	printf_writer(t_ft_printf *context, const void *buf, size_t len)
{
	return (context->writer->base.v->write(
			&context->writer->base, buf, len, NULL));
}

static t_ft_printf	*printf_init(void *param)
{
	t_ft_printf *const	result = (t_ft_printf *) malloc(sizeof(t_ft_printf));

	(void) param;
	if (!result)
		return (NULL);
	result->writer = new_writer_count(
			new_writer_buffered(
				new_writer_fd(1, false),
				1024,
				false
				)
			);
	if (!result->writer)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

static size_t	printf_get_bytes_wrote(t_ft_printf *context)
{
	return (context->writer->count);
}

static t_err	printf_finalize(t_ft_printf *context)
{
	if (context->writer->base.v->delete(&context->writer->base, NULL))
		return (true);
	free(context);
	return (false);
}

static const t_ft_printf_stream_class	g_ft_printf = {
	(t_ft_printf_stream_init)(&printf_init),
	(t_ft_printf_stream_write)(&printf_writer),
	(t_ft_printf_stream_get_bytes_wrote)(&printf_get_bytes_wrote),
	(t_ft_printf_stream_finalize)(&printf_finalize),
};

int	ft_printf(const char *format, ...)
{
	size_t				len;
	va_list				arguments;
	t_ft_printf_stream	stream;
	int					result;

	stream.type = &g_ft_printf;
	va_start(arguments, format);
	if (ft_vprintf_stream(stream, &len, format, arguments) || len > INT_MAX)
		result = -1;
	else
		result = (int) len;
	va_end(arguments);
	return (result);
}
