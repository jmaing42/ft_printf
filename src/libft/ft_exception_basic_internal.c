/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception_basic_internal.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:05:45 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 10:19:59 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exception_basic_internal.h"
#include "ft_exception_basic_methods.h"

#include <stdlib.h>

#include "ft_io.h"
#include "ft_cstring.h"
#include "ft_memory.h"
#include "ft_types.h"

static const t_exception_basic_vtable	g_v = {
{
	(t_exception_v_delete)(&ft_exception_basic_v_delete),
	(t_exception_v_print)(&ft_exception_basic_v_print)
},
	(t_exception_basic_v_getfile)(&ft_exception_basic_v_getfile),
	(t_exception_basic_v_getline)(&ft_exception_basic_v_getline),
	(t_exception_basic_v_add_stacktrace)(&ft_exception_basic_v_add_stacktrace)
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
	result->expose.stacktrace = NULL;
	result->expose.stacktrace_skipped_count = 0;
	ft_memcpy(result->extra, message, length + 1);
	return ((t_exception_basic *)result);
}

t_err	ft_exception_basic_v_add_stacktrace(t_exception_basic *self,
	const char *file,
	int line,
	const char *message
)
{
	t_exception_basic_stacktrace_node_internal	*result;
	size_t										message_size;

	message_size = 0;
	if (message)
		message_size = ft_strlen(message) + 1;
	result = (t_exception_basic_stacktrace_node_internal *)malloc(
			sizeof(t_exception_basic_stacktrace_node_internal) + message_size);
	if (!result)
	{
		self->stacktrace_skipped_count++;
		return (true);
	}
	result->expose.message = NULL;
	if (message)
	{
		ft_memcpy(result->extra, message, message_size);
		result->expose.message = result->extra;
	}
	result->expose.file = file;
	result->expose.line = line;
	result->expose.next = self->stacktrace;
	self->stacktrace = (t_exception_basic_stacktrace_node *) result;
	return (false);
}
