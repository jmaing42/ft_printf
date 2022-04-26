/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:59:25 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/26 21:55:40 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdbool.h>

# include "../../src/libftprintf.h"

typedef int	(*t_printf)(const char *format, ...);

const char	*o(bool condition, const char *str);
void		test_d(t_printf f);
void		test_i(t_printf f);
void		test_o(t_printf f);
void		test_u(t_printf f);
void		test_x(t_printf f);
void		test_capital_x(t_printf f);

#endif
