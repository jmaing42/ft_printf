/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:53:00 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/24 15:19:19 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../../src/libftprintf.h"

typedef int	(*t_printf)(const char *format, ...);

void	test(t_printf f)
{
	f("Hello world!\n");
	f("%d%2d%3d%5.3d%+5.3d%-3d% 2d\n", 42, 42, 42, 42, 42, 42, 42);
	f("%d%2d%3d%5.3d%+5.3d%-3d% 2d\n", -42, -42, -42, -42, -42, -42, -42);
}

int	main(void)
{
	test(&printf);
	test(&ft_printf);
	return (0);
}
