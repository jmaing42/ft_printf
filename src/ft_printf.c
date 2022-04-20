/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:42:53 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/20 17:32:21 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

#include "libftprintf.h"

typedef struct s_ft_printf {
	size_t	wrote;
	int		fd;
}	t_ft_printf;

static t_err	printf_writer(t_ft_printf *context, const void *buf, size_t len)
{
	size_t		remain;
	size_t		to_write;
	ssize_t		wrote;
	const char	*str;

	str = (const char *) buf;
	remain = len;
	while (remain)
	{
		to_write = remain;
		if (to_write > SSIZE_MAX)
			to_write = SSIZE_MAX;
		wrote = write(context->fd, str, to_write);
		if (wrote < 0)
			return (true);
		context->wrote += wrote;
		remain -= (size_t) wrote;
		str = str + wrote;
	}
	return (false);
}

static void	*printf_init(void *param)
{
	t_ft_printf *const	result = (t_ft_printf *) malloc(sizeof(t_ft_printf));

	(void) param;
	if (!result)
		return (NULL);
	result->fd = 1;
	result->wrote = 0;
	return (result);
}

static size_t	printf_get_bytes_wrote(t_ft_printf *context)
{
	return (context->wrote);
}

static const t_ft_printf_stream_class	g_ft_printf = {
	&printf_init,
	(t_ft_printf_stream_write)(&printf_writer),
	(size_t (*)(void *context))(&printf_get_bytes_wrote),
	&free,
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
