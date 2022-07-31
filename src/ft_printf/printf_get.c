/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:47:43 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 15:33:19 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void	*ft_vprintf_get_p(va_list *arguments)
{
	uintptr_t	tmp;

	if (sizeof(void *) < sizeof(unsigned int))
	{
		tmp = va_arg(*arguments, unsigned int);
		return (*((void **)&tmp));
	}
	return (va_arg(*arguments, void *));
}

long double	ft_vprintf_get_double(va_list *arguments)
{
	return ((long double) va_arg(*arguments, double));
}

long double	ft_vprintf_get_long_double(va_list *arguments)
{
	return (va_arg(*arguments, long double));
}
