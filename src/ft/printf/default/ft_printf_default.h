/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_default.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:02:30 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/30 00:43:16 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_DEFAULT_H
# define FT_PRINTF_DEFAULT_H

# include "ft_printf.h"

t_err	ft_printf_default_options_parse_conversion_specifier(
			const char *format_part,
			size_t *out_consumed_length,
			t_ft_printf_options_process_conversion_specifier *out,
			t_ft_printf_options_disposable *context);

t_err	ft_printf_default_options_parse_length_modifier(
			const char *format_part,
			size_t *out_consumed_length,
			void **out_length_modifier,
			t_ft_printf_options_disposable *context);

t_err	ft_printf_default_options_parse_flags(
			const char *format_part,
			size_t *out_consumed_length,
			t_ft_printf_options_process_conversion_specification_flags *out,
			t_ft_printf_options_disposable *context);

#endif
