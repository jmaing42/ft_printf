/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_stream_fd_in_v.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 09:07:33 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/25 09:09:25 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTO_STREAM_FD_IN_V_H
# define FTO_STREAM_FD_IN_V_H

# include "fto_stream_fd_in.h"

t_err	fto_stream_fd_in_v_read(
			t_fto_stream_fd_in *self,
			char *buffer,
			size_t length,
			size_t *read_bytes);
void	fto_stream_fd_in_v_free(
			t_fto_stream_fd_in *self);

#endif