/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_primitive_const_pointer.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:44:45 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/25 00:22:33 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primitive_const_pointer.h"

void	ft_primitive_const_pointer_swap(const void **a, const void **b)
{
	const void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

const void	*ft_primitive_const_pointer_if(
	bool condition,
	const void *value_if_true,
	const void *value_if_false
)
{
	if (condition)
		return (value_if_true);
	return (value_if_false);
}

const void	*ft_primitive_const_pointer_fallback(
	const void *value,
	const void *fallback
)
{
	if (value)
		return (value);
	return (fallback);
}
