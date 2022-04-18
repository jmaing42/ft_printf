/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:15:18 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/18 22:19:37 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>

/*
ft_[v]{,f,s,sn,n,c}printf{,_p}

function name:
	v: accept va_list instead of variable arguments
	f: print to given fd
	s: print to given buffer
	sn: print to given buffer, in given buffer size
	n: precalculate length
	c: c-style string
	_p: positional parameter

conversion:
	any charactor except for %
	%[flags][minimum-length][.precision]conversion-specifier

	flags: one or more of the following
		[-]: left pad (instead of right)
		[+]: (signed number) always show sign
		[ ]: (signed number) print space if no sign, ignored if +
		[#]: alternative format (per conversion-specifier)
		[0]: (number) pad with zero, ignored if - or (integer and precision)

conversion-specifier:
	%: literal %
	c: single char
	s: string
	i: same as d
	d: signed integer, base 10, minimum length is precision default 1
		length: one of below:
			hh: char
			h: short
			: int
			l: long
			ll: long long
			j: intmax_t
			z: size_t
			t: ptrdiff_t
	u: same as d, but unsigned
	o: same as u, but base 8, prefix 0 if alternative
	x: same as u, but base 16, prefix 0x if nonzero and alternative
	X: same as x, but uppercase

see examples in source branch / test files
*/

/**
 * @brief same as printf
 *
 * @return int not ssize_t because of subject compatibility
 */
int		ft_printf(const char *format, ...);
ssize_t	ft_fprintf(int fd, const char *format, ...);
ssize_t	ft_sprintf(char *buffer, const char *format, ...);
ssize_t	ft_snprintf(char *buffer, size_t size, const char *format, ...);
size_t	ft_nprintf(const char *format, ...);
char	*ft_cprintf(const char *format, ...);
ssize_t	ft_vprintf(const char *format, va_list arguments);
ssize_t	ft_vfprintf(int fd, const char *format, va_list arguments);
ssize_t	ft_vsprintf(char *buffer, const char *format, va_list arguments);
ssize_t	ft_vsnprintf(char *buffer, size_t size, const char *format, va_list va);
size_t	ft_vnprintf(const char *format, va_list arguments);
char	*ft_vcprintf(const char *format, va_list arguments);

/*
ssize_t	ft_printf_p(const char *format, ...);
ssize_t	ft_fprintf_p(int fd, const char *format, ...);
ssize_t	ft_sprintf_p(char *buffer, const char *format, ...);
ssize_t	ft_snprintf_p(char *buffer, size_t size, const char *format, ...);
size_t	ft_nprintf_p(const char *format, ...);
char	*ft_cprintf_p(const char *format, ...);
ssize_t	ft_vprintf_p(const char *format, va_list arguments);
ssize_t	ft_vfprintf_p(int fd, const char *format, va_list arguments);
ssize_t	ft_vsprintf_p(char *buffer, const char *format, va_list arguments);
ssize_t	ft_vsnprintf_p(char *buf, size_t size, const char *format, va_list va);
size_t	ft_vnprintf_p(const char *format, va_list arguments);
char	*ft_vcprintf_p(const char *format, va_list arguments);
*/

#endif
