/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_o.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:04:54 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 15:33:19 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_CONVERSION_O_H
# define PRINTF_CONVERSION_O_H

# include "printf_conversion_common.h"

typedef struct s_o
{
	uintmax_t	value;
	int			minimum_field_width;
	int			length;
	bool		left_justified;
	int			precision;
}	t_o;

#endif
