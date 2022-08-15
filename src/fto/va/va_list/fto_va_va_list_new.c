/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_va_va_list_new.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:19:28 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/15 19:07:22 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_va_va_list.h"

#include <stdlib.h>

#include "fto_va_va_list_v.h"

static const t_fto_va_va_list_vtable	g_v = {
	fto_va_va_list_v_free,
	fto_va_va_list_v_get_char,
	fto_va_va_list_v_get_signed_char,
	fto_va_va_list_v_get_signed_short,
	fto_va_va_list_v_get_signed_int,
	fto_va_va_list_v_get_signed_long,
	fto_va_va_list_v_get_signed_long_long,
	fto_va_va_list_v_get_unsigned_char,
	fto_va_va_list_v_get_unsigned_short,
	fto_va_va_list_v_get_unsigned_int,
	fto_va_va_list_v_get_unsigned_long,
	fto_va_va_list_v_get_unsigned_long_long,
	fto_va_va_list_v_get_float,
	fto_va_va_list_v_get_double,
	fto_va_va_list_v_get_long_double,
	fto_va_va_list_v_get_intmax_t,
	fto_va_va_list_v_get_uintmax_t,
	fto_va_va_list_v_get_ssize_t,
	fto_va_va_list_v_get_size_t,
	fto_va_va_list_v_get_ptrdiff_t,
	fto_va_va_list_v_get_pointer,
};

t_fto_va_va_list	*new_fto_va_va_list(va_list *args)
{
	t_fto_va_va_list *const	result = malloc(sizeof(t_fto_va_va_list));

	if (!result)
		return (NULL);
	result->v.v = &g_v;
	result->args = args;
	return (result);
}
