/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_primitive_size_t.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:58:54 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 15:33:19 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_primitive_size_t.h"

void	ft_primitive_size_t_swap(size_t *a, size_t *b)
{
	size_t	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

size_t	ft_primitive_size_t_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t	ft_primitive_size_t_max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

size_t	ft_primitive_size_t_if(
	bool condition,
	size_t value_if_true,
	size_t value_if_false
)
{
	if (condition)
		return (value_if_true);
	else
		return (value_if_false);
}
