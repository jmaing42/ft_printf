/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:17:35 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/18 18:35:38 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <stddef.h>
# include <stdbool.h>

/**
 * @brief safe write wrapper
 *
 * @param fd destination file descriptor
 * @param buf buffer
 * @param len bytes to write
 * @param out_len bytes wrote, set only if error occurred, and not null
 * @return true on error
 * @return false on success
 */
bool	ft_fwrite(int fd, const void *buf, size_t len, size_t *out_len);

#endif
