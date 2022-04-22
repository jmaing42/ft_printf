/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 05:01:05 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/22 09:16:28 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

# ifdef NULL
#  undef NULL
# endif
# define NULL 0

typedef enum e_bool { false, true }	t_bool;
typedef t_bool						t_err;

#endif
