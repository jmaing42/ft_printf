/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_exception_internal.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:21:36 by jmaing            #+#    #+#             */
/*   Updated: 2022/07/25 00:29:36 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTO_EXCEPTION_INTERNAL_H
# define FTO_EXCEPTION_INTERNAL_H

# include "fto_exception.h"

typedef struct s_exception_internal
{
	t_exception	expose;
	char		extra[];
}	t_exception_internal;

typedef struct s_exception_stacktrace_node_internal
{
	t_exception_stacktrace_node	expose;
	char						extra[];
}	t_exception_stacktrace_node_internal;

#endif
