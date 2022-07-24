/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_allocate_helper.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 00:47:59 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/25 00:59:09 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTIL_ALLOCATE_HELPER_H
# define FT_UTIL_ALLOCATE_HELPER_H

# include "ft_types.h"

typedef struct s_ft_util_allocate_helper_node
{
	struct s_ft_util_allocate_helper_node	*next;
	void									*memory;
	void									(*free)(void *memory);
}	t_ft_util_allocate_helper_node;

typedef struct s_ft_util_allocate_helper
{
	t_ft_util_allocate_helper_node	*head;
	t_ft_util_allocate_helper_node	*tail;
}	t_ft_util_allocate_helper;

/**
 * @brief Initialize allocate helper
 *
 * @param self address of allocate helper instance
 */
void	t_ft_util_allocate_helper_init(
			t_ft_util_allocate_helper *self);

/**
 * @brief free all allocated/additional memory, in case of failure
 *
 * @param self address of allocate helper instance
 */
void	t_ft_util_allocate_helper_free(
			t_ft_util_allocate_helper *self);

/**
 * @brief free all additional memory for maintain the helper, in case of success
 *
 * @param self address of allocate helper instance
 */
void	t_ft_util_allocate_helper_clear(
			t_ft_util_allocate_helper *self);

/**
 * @brief put allocation result into the allocate helper
 *
 * @param self address of allocate helper instance
 * @param memory result
 * @param free how to free the memory
 * @return t_err true on error, false on success
 */
t_err	t_ft_util_allocate_helper_put(
			t_ft_util_allocate_helper *self,
			void *memory,
			void (*free)(void *memory));

#endif
