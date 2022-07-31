/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer_count.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:39:06 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/07/31 18:41:47 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WRITER_COUNT_H
# define FT_WRITER_COUNT_H

# include "ft_writer.h"

typedef struct s_writer_count
{
	t_writer	base;
	t_writer	*writer;
	size_t		count;
}	t_writer_count;

t_writer_count	*new_writer_count(t_writer *writer);

#endif
