/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_allocate_helper_init.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:21:53 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/25 23:33:00 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_util_allocate_helper.h"

#include <stddef.h>

void	ft_util_allocate_helper_init(
	t_ft_util_allocate_helper *self
)
{
	self->head = NULL;
}
