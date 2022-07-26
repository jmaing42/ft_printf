/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_string_out_v_unsafe_free.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 19:07:02 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/26 19:14:40 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_string_out_v.h"

#include <stdlib.h>

void	fto_stream_string_out_v_unsafe_free(
	t_fto_stream_string_out *self
)
{
	stringbuilder_free(self->stringbuilder);
	free(self);
}
