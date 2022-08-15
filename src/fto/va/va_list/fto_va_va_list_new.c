/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_va_va_list_new.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:19:28 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/15 17:27:54 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fto_va_va_list.h"

#include <stdlib.h>

static const t_fto_va_vtable	g_v = {
};

t_fto_va_va_list	*new_fto_va_va_list(va_list *args)
{
	t_fto_va_va_list *const	result = malloc(sizeof(t_fto_va_va_list));

	if (!result)
		return (NULL);
		result->v = &g_v;
	result->args = args;
	return (result);
}
