/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf_stream_internal.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 06:26:11 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 06:27:01 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VPRINTF_STREAM_INTERNAL_H
# define FT_VPRINTF_STREAM_INTERNAL_H

# include "ft_vprintf_stream.h"

typedef t_printf_format_conversion_specification	t_conversion;

typedef t_err										(*t_processor)(
		t_ft_vprintf_stream_context *context,
		va_list arguments,
		t_conversion *value);

typedef struct s_conversion_entry {
	t_printf_format_conversion_specifier	type;
	t_processor								process;
}													t_conversion_entry;

#endif
