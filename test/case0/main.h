/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:59:25 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/25 22:22:14 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../../src/libftprintf.h"

typedef int	(*t_printf)(const char *format, ...);

int	test_d(t_printf f);
int	test_o(t_printf f);

#endif
