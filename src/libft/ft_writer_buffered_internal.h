/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer_buffered_internal.h                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:58:15 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/30 08:01:15 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WRITER_BUFFERED_INTERNAL_H
# define FT_WRITER_BUFFERED_INTERNAL_H

# include "ft_writer_buffered.h"

typedef struct s_writer_buffered
{
	t_writer	expose;
	t_writer	*writer;
	size_t		capacity;
	size_t		length;
	bool		close_original_writer_too;
	char		buffer[];
}	t_writer_buffered;

#endif
