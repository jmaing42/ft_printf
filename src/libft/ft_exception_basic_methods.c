/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception_basic_methods.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:53:48 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 09:57:35 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exception_basic_methods.h"

#include <stdlib.h>

#include "ft_io.h"

void	ft_exception_basic_v_delete(t_exception_basic *self)
{
	free(self);
}

t_err	ft_exception_basic_v_print(t_exception_basic *self, int fd)
{
	return (ft_puts(fd, "Error on ", NULL)
		|| ft_puts(fd, self->file, NULL)
		|| ft_puts(fd, " line ", NULL)
		|| ft_putn(fd, self->line, NULL)
		|| ft_puts(fd, ": ", NULL)
		|| ft_puts(fd, self->message, NULL)
		|| ft_puts(fd, "\n", NULL)
	);
}

const char	*ft_exception_basic_v_getfile(t_exception_basic *self)
{
	return (self->file);
}

int	ft_exception_basic_v_getline(t_exception_basic *self)
{
	return (self->line);
}
