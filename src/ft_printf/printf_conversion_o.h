/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_o.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:04:54 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/30 08:01:15 by jmaing           ###   ########.fr       */
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
