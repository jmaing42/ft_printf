/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:50:32 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 13:39:33 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# include <stddef.h>

# include "ft_exception.h"

t_err	ft_write(
			int fd,
			const void *buf,
			size_t len,
			t_exception **out_exception);

t_err	ft_puts(int fd, const char *str, t_exception **out_exception);
t_err	ft_putn(int fd, int n, t_exception **out_exception);
t_err	ft_puts_prefix(
			int fd,
			const char *str,
			const char *prefix,
			t_exception **out_exception);

#endif
