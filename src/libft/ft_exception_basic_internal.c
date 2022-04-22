/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception_basic_internal.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:05:45 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 09:57:10 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exception_basic_internal.h"
#include "ft_exception_basic_methods.h"

#include <stdlib.h>

#include "ft_io.h"
#include "ft_cstring.h"
#include "ft_memory.h"

static const t_exception_basic_vtable	g_v = {
{
	(t_exception_v_delete)(&ft_exception_basic_v_delete),
	(t_exception_v_print)(&ft_exception_basic_v_print)
},
	(t_exception_basic_v_getfile)(&ft_exception_basic_v_getfile),
	(t_exception_basic_v_getline)(&ft_exception_basic_v_getline)
};

t_exception_basic	*new_exception(
	const char *message,
	const char *file,
	int line
)
{
	t_exception_basic_internal	*result;
	const size_t				length = ft_strlen(message);

	result = (t_exception_basic_internal *)malloc(
			sizeof(t_exception_basic_internal) + length + 1);
	if (!result)
		return (NULL);
	result->expose.v = &g_v;
	result->expose.file = file;
	result->expose.line = line;
	result->expose.message = result->extra;
	ft_memcpy(result->extra, message, length + 1);
	return ((t_exception_basic *)result);
}
