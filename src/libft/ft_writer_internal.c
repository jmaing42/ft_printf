/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer_internal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:52:55 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 15:27:13 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_writer.h"

t_err	ft_writer_base_v_default_delete(t_writer *self, t_exception **exception)
{
	if (self->v->flush(self, exception))
	{
		(*exception)->b->add_stacktrace(
			*exception, __FILE__, __LINE__, "Failed to finalize writer");
		return (true);
	}
	self->v->unsafe_delete(self);
	return (false);
}
