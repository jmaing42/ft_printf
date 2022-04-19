/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:42:53 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/19 22:31:57 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

#include "libftprintf.h"

static t_err	ft_write(int fd, const void *buf, size_t len, size_t *inout_len)
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
		wrote = write(fd, str, to_write);
		if (wrote < 0)
			return (true);
		if (inout_len)
			*inout_len += wrote;
		remain -= (size_t) wrote;
		str = str + wrote;
	}
	return (false);
}

static t_err	ft_write_printf_middle(
	bool reset,
	int fd,
	const char *buffer,
	size_t buffer_size
)
{
	static int		g_fd;
	static size_t	g_len;

	if (!reset)
		return (ft_write(g_fd, buffer, buffer_size, &g_len));
	if (buffer)
		*((size_t *)buffer) = g_len;
	g_fd = fd;
	g_len = 0;
	return (true);
}

static t_err	ft_write_printf(
	const char *buffer,
	size_t buffer_size,
	size_t *unused_out_len
)
{
	(void) unused_out_len;
	return (ft_write_printf_middle(false, 1, buffer, buffer_size));
}

int	ft_printf(const char *format, ...)
{
	size_t	out_len;
	bool	result;
	va_list	arguments;

	va_start(arguments, format);
	ft_write_printf_middle(true, 1, NULL, 0);
	result = ft_vprintf_stream(
			&ft_write_printf,
			&out_len,
			format,
			arguments);
	va_end(arguments);
	if (result)
		return (1);
	ft_write_printf_middle(true, 0, (const char *) &out_len, 0);
	return (out_len);
}
