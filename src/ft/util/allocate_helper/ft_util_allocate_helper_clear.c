/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_allocate_helper_clear.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:21:53 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/25 23:33:07 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_util_allocate_helper.h"

#include <stdlib.h>

void	*ft_util_allocate_helper_clear(
	t_ft_util_allocate_helper *self,
	void *result
)
{
	t_ft_util_allocate_helper_node	*next;

	while (self->head)
	{
		next = self->head->next;
		free(self->head);
		self->head = next;
	}
	return (result);
}
