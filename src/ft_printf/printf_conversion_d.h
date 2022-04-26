/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_d.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:07:53 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/26 22:02:09 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_CONVERSION_D_H
# define PRINTF_CONVERSION_D_H

# include "printf_conversion_common.h"

typedef struct s_d {
	intmax_t	value;
	int			minimum_field_width;
	char		sign;
	bool		left_justified;
	int			precision;
}	t_d;

#endif
