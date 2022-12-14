/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_allocate_helper.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 00:47:59 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/25 23:33:26 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTIL_ALLOCATE_HELPER_H
# define FT_UTIL_ALLOCATE_HELPER_H

# include "ft_types.h"

typedef struct s_ft_util_allocate_helper_node
{
	struct s_ft_util_allocate_helper_node	*next;
	void									**memory;
	void									(*free)(void **memory);
}	t_ft_util_allocate_helper_node;

typedef struct s_ft_util_allocate_helper
{
	t_ft_util_allocate_helper_node	*head;
}	t_ft_util_allocate_helper;

/**
 * @brief Initialize allocate helper
 *
 * @param self address of allocate helper instance
 */
void	ft_util_allocate_helper_init(
			t_ft_util_allocate_helper *self);

/**
 * @brief free all allocated/additional memory, in case of failure
 *
 * @param self address of allocate helper instance
 */
void	*ft_util_allocate_helper_free(
			t_ft_util_allocate_helper *self);

/**
 * @brief free all additional memory for maintain the helper, in case of success
 *
 * @param self address of allocate helper instance
 */
void	*ft_util_allocate_helper_clear(
			t_ft_util_allocate_helper *self,
			void *result);

/**
 * @brief put allocation result into the allocate helper
 *
 * @param self address of allocate helper instance
 * @param destination address to store result
 * @param memory result
 * @param free how to free the memory
 * @return t_err true on error, false on success
 */
t_err	ft_util_allocate_helper_put(
			t_ft_util_allocate_helper *self,
			void **destination,
			void *memory,
			void (*free_memory)(void **memory));

#endif
