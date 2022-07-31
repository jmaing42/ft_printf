/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_n_extra.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:53:35 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 15:33:19 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "internal.h"

t_err	ft_vprintf_stream_fini_set_n_hh(size_t size, void *n)
{
	if (size > SCHAR_MAX)
		return (true);
	*((signed char *) n) = (signed char) size;
	return (false);
}

t_err	ft_vprintf_stream_fini_set_n_h(size_t size, void *n)
{
	if (size > SHRT_MAX)
		return (true);
	*((signed short *) n) = (signed short) size;
	return (false);
}

t_err	ft_vprintf_stream_fini_set_n_empty(size_t size, void *n)
{
	if (size > INT_MAX)
		return (true);
	*((signed int *) n) = (signed int) size;
	return (false);
}

t_err	ft_vprintf_stream_fini_set_n_l(size_t size, void *n)
{
	if (size > LONG_MAX)
		return (true);
	*((signed long *) n) = (signed long) size;
	return (false);
}

t_err	ft_vprintf_stream_fini_set_n_ll(size_t size, void *n)
{
	if (size > LLONG_MAX)
		return (true);
	*((signed long long *) n) = (signed long long) size;
	return (false);
}
