/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_writer_fd_internal.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:58:15 by jmaing            #+#    #+#             */
/*   Updated: 2022/07/25 00:34:54 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTO_WRITER_FD_INTERNAL_H
# define FTO_WRITER_FD_INTERNAL_H

# include "fto_writer_fd.h"

typedef struct s_writer_fd
{
	t_writer	expose;
	int			fd;
	bool		close_fd_on_delete;
}	t_writer_fd;

#endif
