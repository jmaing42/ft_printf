/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream_context.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 07:50:33 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/30 08:01:15 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STREAM_CONTEXT_H
# define STREAM_CONTEXT_H

# include "../libft/ft_types.h"

# include "format.h"

typedef void	*(*t_ft_printf_stream_init)(void *param);
typedef t_err	(*t_ft_printf_stream_write)(
	void *self,
	const char *buffer,
	size_t buffer_size
);
typedef size_t	(*t_ft_printf_stream_get_bytes_wrote)(void *self);
typedef t_err	(*t_ft_printf_stream_finalize)(void *self);

typedef struct s_ft_printf_stream_class
{
	t_ft_printf_stream_init				init;
	t_ft_printf_stream_write			writer;
	t_ft_printf_stream_get_bytes_wrote	get_bytes_wrote;
	t_ft_printf_stream_finalize			finalize;
}	t_ft_printf_stream_class;

typedef struct s_ft_vprintf_stream_context_n_list
{
	struct s_ft_vprintf_stream_context_n_list	*next;
	t_printf_format_length_modifier				type;
	void										*value;
}	t_ft_vprintf_stream_context_n_list;

typedef struct s_ft_vprintf_stream_context
{
	t_ft_vprintf_stream_context_n_list	*list;
	const t_ft_printf_stream_class		*stream_class;
	void								*stream;
}	t_ft_vprintf_stream_context;

#endif
