/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception_internal.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:21:36 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 10:55:54 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXCEPTION_INTERNAL_H
# define FT_EXCEPTION_INTERNAL_H

# include "ft_exception.h"

typedef struct s_exception_internal {
	t_exception	expose;
	char		extra[];
}	t_exception_internal;

typedef struct s_exception_stacktrace_node_internal {
	t_exception_stacktrace_node	expose;
	char						extra[];
}	t_exception_stacktrace_node_internal;

#endif
