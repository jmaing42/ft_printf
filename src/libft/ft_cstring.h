/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstring.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 05:28:39 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 06:08:00 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CSTRING_H
# define FT_CSTRING_H

# include <stddef.h>

# include "ft_types.h"

size_t	ft_strlen(const char *str);
size_t	ft_strlen_until(
			const char *str,
			const char *set,
			t_bool include_null);

size_t	ft_strnlen(const char *str, size_t max_len);
size_t	ft_strnlen_until(
			const char *str,
			const char *set,
			size_t max_len,
			t_bool include_null);

#endif
