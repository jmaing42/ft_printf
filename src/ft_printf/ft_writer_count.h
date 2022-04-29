/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer_count.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:39:06 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/30 08:01:15 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WRITER_COUNT_H
# define FT_WRITER_COUNT_H

# include "../libft/ft_writer.h"

typedef struct s_writer_count
{
	t_writer	base;
	t_writer	*writer;
	size_t		count;
}	t_writer_count;

t_writer_count	*new_writer_count(t_writer *writer);

#endif
