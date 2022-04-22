/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception_basic_internal.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:05:45 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 06:09:28 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exception_basic_internal.h"

#include <stdlib.h>

#include "ft_io.h"

static void	exception_basic_print(t_exception_basic *self, int fd)
{
	(void) (ft_puts(fd, "Error on ", (t_exception **) 0)
		|| ft_puts(fd, self->file, (t_exception **) 0)
		|| ft_puts(fd, " line ", (t_exception **) 0)
		|| ft_putn(fd, self->line, (t_exception **) 0)
		|| ft_puts(fd, ": ", (t_exception **) 0)
		|| ft_puts(fd, self->message, (t_exception **) 0)
		|| ft_puts(fd, "\n", (t_exception **) 0)
	);
}

static void	exception_basic_delete(t_exception_basic *self)
{
	free(self);
}

static const t_exception_basic_vtable	g_v = {
{
	(t_exception_v_delete)(&exception_basic_delete),
	(t_exception_v_print)(&exception_basic_print)
}
};

t_exception_basic	*new_exception(
	const char *message,
	const char *file,
	int line
)
{
	t_exception_basic_internal	*result;
	const char					*tmp;
	char						*temp;
	size_t						length;

	length = 1;
	tmp = message - 1;
	while (*++tmp)
		length++;
	result = (t_exception_basic_internal *)malloc(
			sizeof(t_exception_basic_internal) + length);
	if (!result)
		return (NULL);
	result->expose.v = &g_v;
	result->expose.file = file;
	result->expose.line = line;
	result->expose.message = result->extra;
	temp = result->extra;
	while (*message)
		*temp++ = *message++;
	*temp = '\0';
	return ((t_exception_basic *)result);
}
