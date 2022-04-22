/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream_context.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 07:50:33 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 07:52:29 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STREAM_CONTEXT_H
# define STREAM_CONTEXT_H

# include "../libft/ft_types.h"

# include "format.h"

typedef t_err	(*t_ft_printf_stream_write)(
	void *context,
	const char *buffer,
	size_t buffer_size
);

typedef struct s_ft_printf_stream_class {
	void						*(*init)(void *param);
	t_ft_printf_stream_write	writer;
	size_t						(*get_bytes_wrote)(void *context);
	t_err						(*finalize)(void *context);
}	t_ft_printf_stream_class;

typedef struct s_ft_vprintf_stream_context_n_list {
	struct s_ft_vprintf_stream_context_n_list	*next;
	t_printf_format_length_modifier				type;
	void										*value;
}	t_ft_vprintf_stream_context_n_list;

typedef struct s_ft_vprintf_stream_context {
	t_ft_vprintf_stream_context_n_list	*list;
	const t_ft_printf_stream_class		*stream_class;
	void								*stream_context;
}	t_ft_vprintf_stream_context;

#endif
