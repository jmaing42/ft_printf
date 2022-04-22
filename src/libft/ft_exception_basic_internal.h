/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception_basic_internal.h                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:21:36 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 05:28:03 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXCEPTION_BASIC_INTERNAL_H
# define FT_EXCEPTION_BASIC_INTERNAL_H

# include "ft_exception_basic.h"

typedef struct s_exception_basic_internal {
	t_exception_basic	expose;
	char				extra[];
}	t_exception_basic_internal;

#endif
