/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:50:32 by jmaing            #+#    #+#             */
/*   Updated: 2022/07/25 23:35:23 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# include "ft_types.h"

# include <stddef.h>

t_err	ft_write(
			int fd,
			const void *buf,
			size_t len);

t_err	ft_puts(int fd, const char *str);
t_err	ft_putn(int fd, int n);
t_err	ft_puts_prefix(
			int fd,
			const char *str,
			const char *prefix);

#endif
