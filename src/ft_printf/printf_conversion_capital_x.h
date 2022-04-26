/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_capital_x.h                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:04:54 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/26 21:54:29 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_CONVERSION_CAPITAL_X_H
# define PRINTF_CONVERSION_CAPITAL_X_H

# include "printf_conversion_common.h"

typedef struct s_capital_x {
	uintmax_t	value;
	int			length;
	int			precision;
	int			minimum_field_width;
	bool		left;
	bool		prefix;
}	t_capital_x;

#endif
