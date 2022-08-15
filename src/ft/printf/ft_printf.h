/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 00:07:24 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/08/15 20:57:15 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_types.h"

# include "fto_stream_out.h"
# include "fto_va.h"

/**
 * states:
 *
 * 0. error
 * 1. accept any: % - 7, other - 1
 * 2. accept conversion specifier: csdiouxXfFeEaAgGnp or custom - 1, other - 0
 * 3. accept length modifier: hh h (none) l ll L j z t or custom - 2, other - 1
 * 4. accept precision: at least one digit or a asterisk - 3, other - 0
 * 5. accept dot: dot - 4, other - 3
 * 6. accept minimum field width: 5
 * 7. accept any flags: 6 or 0 (custom)
 *
 */

typedef struct s_ft_printf_options_flags_disposable
{
	void	(*dispose)(struct s_ft_printf_options_flags_disposable *self);
}	t_ft_printf_options_flags_disposable;

typedef struct s_ft_printf_options_process_conversion_specification_flags
{
	void									*length_modifier;
	int										minimum_field_width;
	int										precision;
	t_ft_printf_options_flags_disposable	*other;
}	t_ft_printf_options_process_conversion_specification_flags;

typedef t_err	(*t_ft_printf_options_process_conversion_specifier)(
		t_fto_stream_out *stream,
		t_fto_va *va,
		t_ft_printf_options_process_conversion_specification_flags *flags,
		void *context);

typedef t_err	(*t_ft_printf_options_parse_conversion_specifier)(
		const char *format_part,
		size_t *consumed_length,
		t_ft_printf_options_process_conversion_specifier *out,
		void *context);

typedef t_err	(*t_ft_printf_options_parse_length_modifier)(
		const char *format_part,
		size_t *consumed_length,
		void **out_length_modifier,
		void *context);

typedef t_err	(*t_ft_printf_options_parse_flags)(
		const char *format_part,
		size_t *consumed_length,
		t_ft_printf_options_process_conversion_specification_flags *out_flags,
		void *context);

typedef struct s_ft_printf_conversion_specification
{
	t_ft_printf_options_process_conversion_specifier			type;
	t_ft_printf_options_process_conversion_specification_flags	options;
}	t_ft_printf_conversion_specification;

typedef struct s_ft_printf_options
{
	t_ft_printf_options_parse_conversion_specifier	parse_conversion_specifier;
	t_ft_printf_options_parse_length_modifier		parse_length_modifier;
	t_ft_printf_options_parse_flags					parse_flags;
	void											*context;
}	t_ft_printf_options;

typedef struct s_ft_printf_input
{
	const char	*format;
	t_fto_va	*va;
}	t_ft_printf_input;

t_err				ft_printf_va_stream(
						t_fto_stream_out *stream,
						t_ft_printf_input input,
						t_ft_printf_options *options);
t_err				ft_printf_va_string(
						char **out,
						size_t *out_length,
						t_ft_printf_input input,
						t_ft_printf_options *options);
t_err				ft_printf_va_fd(
						int fd,
						size_t *out_length,
						t_ft_printf_input input,
						t_ft_printf_options *options);

int					ft_printf(
						const char *format,
						...);

t_ft_printf_options	*ft_printf_get_default_options(void);

#endif
