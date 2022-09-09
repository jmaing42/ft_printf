/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_char.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 01:53:11 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/10 01:55:32 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_CHAR_H
# define FT_TYPES_CHAR_H

# include <stdbool.h>

bool	ft_types_char_alnum(char c);
bool	ft_types_char_alpha(char c);
bool	ft_types_char_ascii(char c);
bool	ft_types_char_blank(char c);
bool	ft_types_char_cntrl(char c);
bool	ft_types_char_digit(char c);
bool	ft_types_char_graph(char c);
bool	ft_types_char_lower(char c);
bool	ft_types_char_print(char c);
bool	ft_types_char_punct(char c);
bool	ft_types_char_space(char c);
bool	ft_types_char_upper(char c);
bool	ft_types_char_xdigit(char c);
bool	ft_types_char_lower(char c);
bool	ft_types_char_upper(char c);

#endif
