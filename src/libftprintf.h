/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:15:18 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 05:41:00 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>

# include "libft/ft_types.h"

/**
 * @brief same as printf
 */
int		ft_printf(const char *format, ...);

typedef t_err	(*t_ft_printf_stream_write)(
	void *context,
	const char *buffer,
	size_t buffer_size
);

typedef struct s_ft_printf_stream_class {
	void						*(*init)(void *param);
	t_ft_printf_stream_write	writer;
	size_t						(*get_bytes_wrote)(void *context);
	t_err						(*finalize)(void *context);
}	t_ft_printf_stream_class;

typedef struct s_ft_printf_stream {
	const t_ft_printf_stream_class	*type;
	void							*param;
}	t_ft_printf_stream;

/**
 * @brief printf for stream accepts va_list
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
			va_list arguments);

#endif
