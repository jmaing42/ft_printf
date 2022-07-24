/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_writer_fd.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:54:45 by jmaing            #+#    #+#             */
/*   Updated: 2022/07/25 00:35:11 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTO_WRITER_FD_H
# define FTO_WRITER_FD_H

# include "fto_writer.h"

t_writer	*new_writer_fd(int fd, bool close_fd_on_delete);

#endif
