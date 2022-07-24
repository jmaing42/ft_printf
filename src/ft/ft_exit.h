/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:10:15 by jmaing            #+#    #+#             */
/*   Updated: 2022/06/27 03:10:04 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXIT_H
# define FT_EXIT_H

# include <stdlib.h>

typedef void	(*t_ft_exit_cleanup_function)();

int		ft_exit(signed char status);
void	ft_set_exit_handler(void (*cleanup)());

#endif
