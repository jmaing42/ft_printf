/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer_fd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:54:45 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 13:13:57 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WRITER_FD_H
# define FT_WRITER_FD_H

# include "ft_writer.h"

t_writer	*new_writer_fd(int fd, bool close_fd_on_delete);

#endif
