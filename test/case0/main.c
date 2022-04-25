/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:53:00 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/25 22:23:39 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "main.h"

int	test(t_printf f)
{
	return (0
		|| test_d(f)
		|| test_o(f)
		|| 0
	);
}

int	main(int argc, char **argv)
{
	(void) argv;
	if (argc < 2)
		return (test(&ft_printf));
	return (test(&printf));
}
