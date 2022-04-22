/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:50:32 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 06:09:44 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# include <stddef.h>

# include "ft_exception.h"

int	ft_write(
		int fd,
		const void *buf,
		size_t len,
		t_exception **out_exception);

int	ft_puts(int fd, const char *str, t_exception **out_exception);
int	ft_putn(int fd, int n, t_exception **out_exception);

#endif
