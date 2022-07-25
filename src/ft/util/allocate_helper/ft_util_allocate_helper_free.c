/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_allocate_helper_free.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:21:53 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/25 23:33:04 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_util_allocate_helper.h"

#include <stdlib.h>

void	*ft_util_allocate_helper_free(
	t_ft_util_allocate_helper *self
)
{
	t_ft_util_allocate_helper_node	*next;

	while (self->head)
	{
		next = self->head->next;
		self->head->free(self->head->memory);
		free(self->head);
		self->head = next;
	}
	return (NULL);
}
