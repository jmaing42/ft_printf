/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_percent.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:12:37 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/20 19:38:50 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_err	ft_vprintf_stream_percent(
	t_ft_vprintf_stream_context *context,
	va_list arguments,
	t_printf_format_conversion_specification *conversion
)
{
	(void) arguments;
	(void) conversion;
	return (context->stream_class->writer(context->stream_context, "%", 1));
}
