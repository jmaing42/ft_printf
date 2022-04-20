/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:57:44 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/20 20:59:36 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <stddef.h>

size_t	ft_strlen(const char *str);
size_t	ft_strlen_until(const char *str, const char *set);
size_t	ft_strnlen(const char *str, size_t max_len);
size_t	ft_strnlen_until(const char *str, const char *set, size_t max_len);

#endif
