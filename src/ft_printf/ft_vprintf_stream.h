/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf_stream.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 00:41:07 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 18:41:47 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VPRINTF_STREAM_H
# define FT_VPRINTF_STREAM_H

# include <stddef.h>
# include <stdarg.h>

# include "ft_types.h"
# include "stream_context.h"
# include "format.h"

typedef struct s_ft_printf_stream
{
	const t_ft_printf_stream_class	*type;
	void							*param;
}	t_ft_printf_stream;

/**
 * @brief printf for stream accepts pointer to va_list
 *
 * @param stream destination
 * @param out_bytes_wrote bytes wrote
 * @param format format in printf
 * @param arguments variables
 * @return true on failure
 * @return false on success
 */
t_err	ft_vprintf_stream(
			const t_ft_printf_stream stream,
			size_t *out_bytes_wrote,
			const char *format,
			va_list *arguments);

#endif
