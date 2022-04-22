/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_common.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 22:31:17 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 06:21:14 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_CONVERSION_COMMON_H
# define PRINTF_CONVERSION_COMMON_H

# include "internal.h"

size_t	ft_vprintf_stream_i_length(
			intmax_t i,
			unsigned int base);
size_t	ft_vprintf_stream_i_put(
			t_ft_vprintf_stream_context *context,
			intmax_t i,
			unsigned int base,
			const char *set);
size_t	ft_vprintf_stream_u_length(
			uintmax_t u,
			unsigned int base);
size_t	ft_vprintf_stream_u_put(
			t_ft_vprintf_stream_context *context,
			uintmax_t u,
			unsigned int base,
			const char *set);

#endif
