/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstring_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:00:11 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 05:37:24 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cstring.h"

#include <limits.h>

static void	bake(const char *set, t_bool include_null, char *out)
{
	size_t				i;
	const unsigned char	*tmp;

	i = 0;
	while (i < 2 << CHAR_BIT)
		out[i++] = 0;
	if (include_null)
		out[0] = 1;
	if (!set)
		return ;
	tmp = (const unsigned char *) set;
	while (*tmp)
		out[*tmp++] = 1;
}

size_t	ft_strlen(const char *str)
{
	size_t	result;

	result = 0;
	while (*str)
	{
		str++;
		result++;
	}
	return (result);
}

size_t	ft_strlen_until(
	const char *str,
	const char *set,
	t_bool include_null
)
{
	size_t	result;
	char	baked[2 << CHAR_BIT];

	bake(set, include_null, baked);
	result = 0;
	while (!baked[*((const unsigned char *) set)])
	{
		str++;
		result++;
	}
	return (result);
}

size_t	ft_strnlen(const char *str, size_t max_len)
{
	size_t	result;

	result = 0;
	while (*str && max_len > result)
	{
		str++;
		result++;
	}
	return (result);
}

size_t	ft_strnlen_until(
	const char *str,
	const char *set,
	size_t max_len,
	t_bool include_null
)
{
	size_t	result;
	char	baked[2 << CHAR_BIT];

	bake(set, include_null, baked);
	result = 0;
	while (max_len > result && !baked[*((const unsigned char *) set)])
	{
		str++;
		result++;
	}
	return (result);
}
