/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 00:39:47 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/24 14:39:12 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_vprintf_stream.h"
# include "ft_writer_count.h"

typedef struct s_ft_printf {
	t_writer_count	*writer;
}	t_ft_printf;

#endif
