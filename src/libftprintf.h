/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:15:18 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/19 22:07:40 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdbool.h>
# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>

typedef bool	t_err;

/**
 * @brief same as printf
 */
int		ft_printf(const char *format, ...);

typedef t_err	(*t_ft_printf_stream)(
	const char *buffer,
	size_t buffer_size,
	size_t *out_len
);

/**
 * @brief printf for stream accepts va_list
 *
 * @param stream destination
 * @param format format in printf
 * @param va_list variables
 * @return true on failure
 * @return false on success
 */
t_err	ft_vprintf_stream(
			t_ft_printf_stream stream,
			size_t *inout_bytes_wrote,
			const char *format,
			va_list arguments);

#endif
