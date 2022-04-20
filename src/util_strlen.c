/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:00:11 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/20 21:08:41 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "util.h"

static void	bake(const char *set, char *out)
{
	size_t				i;
	const unsigned char	*tmp;

	i = 0;
	while (i < 2 << CHAR_BIT)
		out[i++] = 0;
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

size_t	ft_strlen_until(const char *str, const char *set)
{
	size_t	result;
	char	baked[2 << CHAR_BIT];

	bake(set, baked);
	result = 0;
	while (*str && !baked[*((const unsigned char *) set)])
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

size_t	ft_strnlen_until(const char *str, const char *set, size_t max_len)
{
	size_t	result;
	char	baked[2 << CHAR_BIT];

	bake(set, baked);
	result = 0;
	while (*str && max_len > result && !baked[*((const unsigned char *) set)])
	{
		str++;
		result++;
	}
	return (result);
}
