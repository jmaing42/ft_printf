/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:53:00 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/25 14:36:24 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../../src/libftprintf.h"

typedef int	(*t_printf)(const char *format, ...);

const char	*g_test_d[] = {
	"\"%d\"",
	"\"% d\"",
	"\"%+d\"",
	"\"%-d\"",
	"\"%0d\"",
	"\"%#d\"",
	"\"% +d\"",
	"\"% -d\"",
	"\"% 0d\"",
	"\"% #d\"",
	"\"%+-d\"",
	"\"%+0d\"",
	"\"%+#d\"",
	"\"%-0d\"",
	"\"%-#d\"",
	"\"%0#d\"",
	NULL
};

int	test(t_printf f)
{
	const char	**fmt;

	fmt = g_test_d - 1;
	while (*++fmt)
	{
		f("format: %s => ", *fmt);
		f(*fmt, 42424242);
		f("\n");
	}
	return (0);
}

int	main(int argc, char **argv)
{
	(void) argv;
	if (argc < 2)
		return (test(&ft_printf));
	return (test(&printf));
}
