/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:47:43 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/17 19:31:41 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

void	*ft_vprintf_get_p(va_list *arguments)
{
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
