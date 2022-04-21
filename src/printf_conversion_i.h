/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion_i.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 22:31:17 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/20 22:34:49 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_CONVERSION_I_H
# define PRINTF_CONVERSION_I_H

# include "printf.h"

size_t	ft_vprintf_stream_i_length(
			intmax_t i,
			unsigned int base);
size_t	ft_vprintf_stream_i_put(
			t_ft_vprintf_stream_context *context,
			intmax_t i,
			unsigned int base,
			const char *set);

#endif
