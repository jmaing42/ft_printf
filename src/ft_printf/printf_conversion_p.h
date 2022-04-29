/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_p.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:04:54 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/30 08:01:15 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_CONVERSION_P_H
# define PRINTF_CONVERSION_P_H

# include "printf_conversion_common.h"

typedef struct s_p
{
	uintmax_t	value;
	int			length;
	int			precision;
	int			minimum_field_width;
	bool		left;
}	t_p;

#endif
