/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_primitive_pointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:44:45 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/25 00:23:37 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primitive_pointer.h"

void	ft_primitive_pointer_swap(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	*ft_primitive_pointer_if(
	bool condition,
	void *value_if_true,
	void *value_if_false
)
{
	if (condition)
		return (value_if_true);
	return (value_if_false);
}

void	*ft_primitive_const_pointer_fallback(
	void *value,
	void *fallback
)
{
	if (value)
		return (value);
	return (fallback);
}
