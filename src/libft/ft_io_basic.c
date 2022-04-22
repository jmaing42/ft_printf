/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:50:32 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 06:10:00 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_io.h"

#include "ft_exception_basic.h"

#define WRITE_SIZE_MAX 1048576

int	ft_write(
	int fd,
	const void *buf,
	size_t len,
	t_exception **out_exception
)
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
		if (to_write > WRITE_SIZE_MAX)
			to_write = WRITE_SIZE_MAX;
		wrote = write(fd, str, to_write);
		if (wrote < 0)
		{
			if (out_exception)
				*out_exception = (t_exception *) new_exception(
						"write() failed", __FILE__, __LINE__);
			return (1);
		}
		remain -= (size_t) wrote;
		str = str + wrote;
	}
	return (0);
}

int	ft_puts(int fd, const char *str, t_exception **out_exception)
{
	size_t		length;
	const char	*tmp;

	length = 0;
	tmp = str;
	while (*tmp)
	{
		length++;
		tmp++;
	}
	return (ft_write(fd, str, length, out_exception));
}

static int	ft_putn_internal(int fd, int i, t_exception **out_exception)
{
	int	sgn;

	sgn = 1;
	if (i < 0)
		sgn = -1;
	if (!i)
		return (0);
	return (ft_putn_internal(fd, i / 10, out_exception)
		|| ft_write(fd, "0123456789" + (i % 10) * sgn, 1, out_exception));
}

int	ft_putn(int fd, int i, t_exception **out_exception)
{
	if (!i)
		return (ft_puts(fd, "0", out_exception));
	return (ft_putn_internal(fd, i, out_exception));
}
