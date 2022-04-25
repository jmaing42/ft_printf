/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_max_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:35:03 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/25 17:53:24 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

signed char	ft_max_hhd(signed char a, signed char b)
{
	if (a > b)
		return (a);
	return (b);
}

short	ft_max_hd(short a, short b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_max_d(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

long	ft_max_ld(long a, long b)
{
	if (a > b)
		return (a);
	return (b);
}

long long	ft_max_lld(long long a, long long b)
{
	if (a > b)
		return (a);
	return (b);
}
