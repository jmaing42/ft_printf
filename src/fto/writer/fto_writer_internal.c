/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_writer_internal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:52:55 by jmaing            #+#    #+#             */
/*   Updated: 2022/07/25 00:35:16 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_writer.h"

t_err	ft_writer_base_v_default_close(t_writer *self, t_exception **exception)
{
	if (self->v->flush(self, exception))
	{
		if (exception && *exception)
			(*exception)->b->add_stacktrace(
				*exception, __FILE__, __LINE__, NULL);
		return (true);
	}
	self->v->unsafe_close(self);
	return (false);
}

t_err	ft_writer_base_v_default_flush(t_writer *self, t_exception **exception)
{
	(void) self;
	(void) exception;
	return (false);
}
