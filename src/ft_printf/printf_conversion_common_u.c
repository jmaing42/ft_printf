/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_common_u.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 22:34:12 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/26 18:51:07 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_conversion_common.h"

size_t	ft_vprintf_stream_u_length(
	uintmax_t u,
	unsigned int base
)
{
	size_t	result;

	result = 0;
	while (u)
	{
		u /= base;
		result++;
	}
	return (result);
}

static size_t	ft_vprintf_stream_u_put_internal(
	t_ft_vprintf_stream_context *context,
	uintmax_t u,
	unsigned int base,
	const char *set
)
{
	if (!u)
		return (0);
	return (ft_vprintf_stream_u_put_internal(context, u / base, base, set)
		|| context->stream_class->writer(
			context->stream, set + (u % base), 1));
}

size_t	ft_vprintf_stream_u_put(
	t_ft_vprintf_stream_context *context,
	uintmax_t u,
	unsigned int base,
	const char *set
)
{
	return (ft_vprintf_stream_u_put_internal(context, u, base, set));
}
