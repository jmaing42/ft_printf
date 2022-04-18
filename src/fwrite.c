/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fwrite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:50:32 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/18 18:35:44 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>

#include "util.h"

bool	ft_fwrite(int fd, const void *buf, size_t len, size_t *out_len)
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
		{
			if (out_len)
				*out_len = len - remain;
			return (true);
		}
		remain -= (size_t) wrote;
		str = str + wrote;
	}
	return (false);
}
