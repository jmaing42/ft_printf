/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_primitive_int.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:58:38 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 15:33:19 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRIMITIVE_INT_H
# define FT_PRIMITIVE_INT_H

# include <stddef.h>
# include <stdbool.h>

void	ft_primitive_int_swap(int *a, int *b);
int		ft_primitive_int_min(int a, int b);
int		ft_primitive_int_max(int a, int b);
int		ft_primitive_int_if(
			bool condition,
			int value_if_true,
			int value_if_false);

#endif
