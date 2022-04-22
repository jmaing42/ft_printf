/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer_fd_internal.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:58:15 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 13:15:58 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WRITER_FD_INTERNAL_H
# define FT_WRITER_FD_INTERNAL_H

# include "ft_writer_fd.h"

typedef struct s_writer_fd {
	t_writer	expose;
	int			fd;
	bool		close_fd_on_delete;
}	t_writer_fd;

#endif
