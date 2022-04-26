/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:53:00 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/26 21:53:29 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "main.h"

void	test(t_printf f)
{
	test_d(f);
	test_i(f);
	test_o(f);
	test_u(f);
	test_x(f);
}

int	main(int argc, char **argv)
{
	(void) argv;
	if (argc < 2)
		test(&ft_printf);
	else
		test(&printf);
	return (0);
}
