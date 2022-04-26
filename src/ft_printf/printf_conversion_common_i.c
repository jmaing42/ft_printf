/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_common_i.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 22:34:12 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/26 18:50:56 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_conversion_common.h"

size_t	ft_vprintf_stream_i_length(
	intmax_t i,
	unsigned int base
)
{
	size_t	result;

	result = 0;
	while (i)
	{
		i /= base;
		result++;
	}
	return (result);
}

static size_t	ft_vprintf_stream_i_put_internal(
	t_ft_vprintf_stream_context *context,
	intmax_t i,
	unsigned int base,
	const char *set
)
{
	intmax_t	sgn;

	sgn = 1;
	if (i < 0)
		sgn = -1;
	if (!i)
		return (false);
	return (ft_vprintf_stream_i_put_internal(context, i / base, base, set)
		|| context->stream_class->writer(
			context->stream, set + (i % base) * sgn, 1));
}

size_t	ft_vprintf_stream_i_put(
	t_ft_vprintf_stream_context *context,
	intmax_t i,
	unsigned int base,
	const char *set
)
{
	return (ft_vprintf_stream_i_put_internal(context, i, base, set));
}
