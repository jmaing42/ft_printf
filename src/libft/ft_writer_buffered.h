/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer_buffered.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:39:06 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 14:02:42 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WRITER_BUFFERED_H
# define FT_WRITER_BUFFERED_H

# include "ft_writer.h"

t_writer	*new_writer_buffered(t_writer *writer, size_t buffer_size);

#endif
