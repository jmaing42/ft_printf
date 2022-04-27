/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_default.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:18:13 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/28 01:18:14 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_default.h"

void	*ft_default_p(void *value, void *fallback)
{
	if (!value)
		return (fallback);
	return (value);
}

const void	*ft_default_cp(const void *value, const void *fallback)
{
	if (!value)
		return (fallback);
	return (value);
}
