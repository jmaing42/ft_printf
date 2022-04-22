/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception_methods.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:53:48 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 11:11:53 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exception_methods.h"

#include <stdlib.h>

#include "ft_io.h"

void	ft_exception_v_delete(t_exception *self)
{
	t_exception_stacktrace_node	*tmp;

	while (self->stacktrace)
	{
		tmp = self->stacktrace;
		self->stacktrace = self->stacktrace->next;
		free(tmp);
	}
	free(self);
}

static t_err	print_stacktrace(t_exception *self, int fd)
{
	t_exception_stacktrace_node	*node;

	node = self->stacktrace;
	while (node)
	{
		if (ft_puts(fd, "\tAt ", NULL)
			|| ft_puts(fd, node->file, NULL)
			|| ft_puts(fd, ":", NULL)
			|| ft_putn(fd, node->line, NULL)
			|| (node->message
				&& (ft_puts(fd, " - ", NULL)
					|| ft_puts_prefix(fd, node->message, "\t|\t", NULL)
				))
			|| ft_puts(fd, "\n", NULL)
		)
			return (true);
		node = node->next;
	}
	return (false);
}

t_err	ft_exception_v_print(t_exception *self, int fd)
{
	return (ft_puts(fd, "Error on ", NULL)
		|| ft_puts(fd, self->file, NULL)
		|| ft_puts(fd, " line ", NULL)
		|| ft_putn(fd, self->line, NULL)
		|| ft_puts_prefix(fd, ": ", "|\t", NULL)
		|| ft_puts(fd, self->message, NULL)
		|| ft_puts(fd, "\nstacktrace:\n", NULL)
		|| print_stacktrace(self, fd)
	);
}

const char	*ft_exception_v_getfile(t_exception *self)
{
	return (self->file);
}

int	ft_exception_v_getline(t_exception *self)
{
	return (self->line);
}
