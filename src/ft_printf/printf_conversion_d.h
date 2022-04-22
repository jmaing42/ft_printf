/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_d.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 00:36:55 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 05:42:30 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_CONVERSION_D_H
# define PRINTF_CONVERSION_D_H

# include "printf_conversion_common.h"

typedef struct s_d {
	intmax_t	value;
	int			length;
	t_bool		left;
	char		sign;
}	t_d;

#endif
