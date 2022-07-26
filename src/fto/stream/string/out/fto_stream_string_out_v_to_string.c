/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_string_out_v_to_string.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 19:15:17 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/26 19:16:31 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_stream_string_out_v.h"

char	*fto_stream_string_out_v_to_string(
	t_fto_stream_string_out *self
)
{
	return (stringbuilder_to_string(self->stringbuilder, 0));
}
