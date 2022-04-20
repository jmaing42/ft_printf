/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_get_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:47:43 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/20 15:03:33 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

uintmax_t	ft_vprintf_get_u(va_list arguments)
{
	return ((uintmax_t) va_arg(arguments, unsigned int));
}

uintmax_t	ft_vprintf_get_lu(va_list arguments)
{
	return ((uintmax_t) va_arg(arguments, unsigned long));
}

uintmax_t	ft_vprintf_get_llu(va_list arguments)
{
	return ((uintmax_t) va_arg(arguments, unsigned long long));
}

uintmax_t	ft_vprintf_get_ju(va_list arguments)
{
	return (va_arg(arguments, uintmax_t));
}

uintmax_t	ft_vprintf_get_zu(va_list arguments)
{
	return ((uintmax_t) va_arg(arguments, size_t));
}
