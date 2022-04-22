/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_n_extra.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:53:35 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 06:21:14 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "internal.h"

t_err	ft_vprintf_stream_fini_set_n_hh(size_t size, void *n)
{
	if (size > SCHAR_MAX)
		return (false);
	*((signed char *) n) = (signed char) size;
	return (true);
}

t_err	ft_vprintf_stream_fini_set_n_h(size_t size, void *n)
{
	if (size > SHRT_MAX)
		return (false);
	*((signed short *) n) = (signed short) size;
	return (true);
}

t_err	ft_vprintf_stream_fini_set_n_empty(size_t size, void *n)
{
	if (size > INT_MAX)
		return (false);
	*((signed int *) n) = (signed int) size;
	return (true);
}

t_err	ft_vprintf_stream_fini_set_n_l(size_t size, void *n)
{
	if (size > LONG_MAX)
		return (false);
	*((signed long *) n) = (signed long) size;
	return (true);
}

t_err	ft_vprintf_stream_fini_set_n_ll(size_t size, void *n)
{
	if (size > LLONG_MAX)
		return (false);
	*((signed long long *) n) = (signed long long) size;
	return (true);
}
