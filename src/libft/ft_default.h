/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_default.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 01:15:38 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/28 01:17:29 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEFAULT_H
# define FT_DEFAULT_H

void		*ft_default_p(void *value, void *fallback);
const void	*ft_default_cp(const void *value, const void *fallback);

#endif
