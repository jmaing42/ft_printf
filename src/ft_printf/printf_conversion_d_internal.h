/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_d_internal.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:07:53 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/25 21:05:51 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_CONVERSION_D_INTERNAL_H
# define PRINTF_CONVERSION_D_INTERNAL_H

# include "printf_conversion_common.h"

typedef struct s_d {
	intmax_t	value;
	int			minimum_field_width;
	char		sign;
	bool		left_justified;
	int			precision;
}	t_d;

t_err	ft_vprintf_stream_d_zero_fill(
			t_ft_vprintf_stream_context *context,
			t_d *d
			);

t_err	ft_vprintf_stream_d_with_precision(
			t_ft_vprintf_stream_context *context,
			t_d *d
			);

t_err	ft_vprintf_stream_d_without_precision(
			t_ft_vprintf_stream_context *context,
			t_d *d
			);

#endif
