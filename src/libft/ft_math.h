/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:14:32 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/25 17:45:10 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <stddef.h>
# include <stdint.h>
# include <sys/types.h>

unsigned char		ft_max_hhu(unsigned char a, unsigned char b);
unsigned short		ft_max_hu(unsigned short a, unsigned short b);
unsigned int		ft_max_u(unsigned int a, unsigned int b);
unsigned long		ft_max_lu(unsigned long a, unsigned long b);
unsigned long long	ft_max_llu(unsigned long long a, unsigned long long b);
size_t				ft_max_zu(size_t a, size_t b);
uintmax_t			ft_max_umax(uintmax_t a, uintmax_t b);
uintptr_t			ft_ptr_uptr(uintptr_t a, uintptr_t b);
uint8_t				ft_max_u8(uint8_t a, uint8_t b);
uint16_t			ft_max_u16(uint16_t a, uint16_t b);
uint32_t			ft_max_u32(uint32_t a, uint32_t b);
uint64_t			ft_max_u64(uint64_t a, uint64_t b);
uint_least8_t		ft_max_u8least(uint_least8_t a, uint_least8_t b);
uint_least16_t		ft_max_u16least(uint_least16_t a, uint_least16_t b);
uint_least32_t		ft_max_u32least(uint_least32_t a, uint_least32_t b);
uint_least64_t		ft_max_u64least(uint_least64_t a, uint_least64_t b);
uint_fast8_t		ft_max_u8fast(uint_fast8_t a, uint_fast8_t b);
uint_fast16_t		ft_max_u16fast(uint_fast16_t a, uint_fast16_t b);
uint_fast32_t		ft_max_u32fast(uint_fast32_t a, uint_fast32_t b);
uint_fast64_t		ft_max_u64fast(uint_fast64_t a, uint_fast64_t b);
signed char			ft_max_hhd(signed char a, signed char b);
short				ft_max_hd(short a, short b);
int					ft_max_d(int a, int b);
long				ft_max_ld(long a, long b);
long long			ft_max_lld(long long a, long long b);
ssize_t				ft_max_zd(size_t a, size_t b);
ptrdiff_t			ft_max_td(ptrdiff_t a, ptrdiff_t b);
intmax_t			ft_max_imax(intmax_t a, intmax_t b);
intptr_t			ft_ptr_iptr(intptr_t a, intptr_t b);
int8_t				ft_max_i8(int8_t a, int8_t b);
int16_t				ft_max_i16(int16_t a, int16_t b);
int32_t				ft_max_i32(int32_t a, int32_t b);
int64_t				ft_max_i64(int64_t a, int64_t b);
int_least8_t		ft_max_i8least(int_least8_t a, int_least8_t b);
int_least16_t		ft_max_i16least(int_least16_t a, int_least16_t b);
int_least32_t		ft_max_i32least(int_least32_t a, int_least32_t b);
int_least64_t		ft_max_i64least(int_least64_t a, int_least64_t b);
int_fast8_t			ft_max_i8fast(int_fast8_t a, int_fast8_t b);
int_fast16_t		ft_max_i16fast(int_fast16_t a, int_fast16_t b);
int_fast32_t		ft_max_i32fast(int_fast32_t a, int_fast32_t b);
int_fast64_t		ft_max_i64fast(int_fast64_t a, int_fast64_t b);

#endif
