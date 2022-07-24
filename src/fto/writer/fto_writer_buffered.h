/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_writer_buffered.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:39:06 by jmaing            #+#    #+#             */
/*   Updated: 2022/07/25 00:34:35 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTO_WRITER_BUFFERED_H
# define FTO_WRITER_BUFFERED_H

# include "fto_writer.h"

t_writer	*new_writer_buffered(
				t_writer *writer,
				size_t buffer_size,
				size_t close_original_writer_too);

#endif
