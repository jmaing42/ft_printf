/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_allocate_helper_put.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:21:53 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/25 23:33:57 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_util_allocate_helper.h"

#include <stdlib.h>

t_err	ft_util_allocate_helper_put(
	t_ft_util_allocate_helper *self,
	void **destination,
	void *memory,
	void (*free_memory)(void **memory)
)
{
	t_ft_util_allocate_helper_node *const	node
		= malloc(sizeof(t_ft_util_allocate_helper_node));

	*destination = memory;
	if (!memory || !node)
	{
		free(node);
		if (memory)
			free_memory(destination);
		return (true);
	}
	node->next = self->head;
	node->free = free_memory;
	node->memory = destination;
	self->head = node;
	return (false);
}
