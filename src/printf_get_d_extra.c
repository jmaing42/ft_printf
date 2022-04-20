/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_get_d_extra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:47:43 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/20 15:03:45 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

intmax_t	ft_vprintf_get_ld(va_list arguments)
{
	return ((intmax_t) va_arg(arguments, long));
}

intmax_t	ft_vprintf_get_lld(va_list arguments)
{
	return ((intmax_t) va_arg(arguments, long long));
}

intmax_t	ft_vprintf_get_jd(va_list arguments)
{
	return (va_arg(arguments, intmax_t));
}

intmax_t	ft_vprintf_get_zd(va_list arguments)
{
	return ((intmax_t) va_arg(arguments, ssize_t));
}

intmax_t	ft_vprintf_get_td(va_list arguments)
{
	return ((intmax_t) va_arg(arguments, ptrdiff_t));
}
