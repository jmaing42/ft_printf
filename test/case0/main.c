/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:53:00 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/25 16:42:09 by jmaing           ###   ########.fr       */
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
	"\"% +d\"",
	"\"% -d\"",
	"\"% 0d\"",
	"\"%+-d\"",
	"\"%+0d\"",
	"\"%-0d\"",
	"\"% +-d\"",
	"\"% +0d\"",
	"\"% -0d\"",
	"\"%+-0d\"",
	"\"% +-0d\"",
	"\"%8d\"",
	"\"% 8d\"",
	"\"%+8d\"",
	"\"%-8d\"",
	"\"%08d\"",
	"\"% +8d\"",
	"\"% -8d\"",
	"\"% 08d\"",
	"\"%+-8d\"",
	"\"%+08d\"",
	"\"%-08d\"",
	"\"% +-8d\"",
	"\"% +08d\"",
	"\"% -08d\"",
	"\"%+-08d\"",
	"\"% +-08d\"",
	"\"%9d\"",
	"\"% 9d\"",
	"\"%+9d\"",
	"\"%-9d\"",
	"\"%09d\"",
	"\"% +9d\"",
	"\"% -9d\"",
	"\"% 09d\"",
	"\"%+-9d\"",
	"\"%+09d\"",
	"\"%-09d\"",
	"\"% +-9d\"",
	"\"% +09d\"",
	"\"% -09d\"",
	"\"%+-09d\"",
	"\"% +-09d\"",
	"\"%10d\"",
	"\"% 10d\"",
	"\"%+10d\"",
	"\"%-10d\"",
	"\"%010d\"",
	"\"% +10d\"",
	"\"% -10d\"",
	"\"% 010d\"",
	"\"%+-10d\"",
	"\"%+010d\"",
	"\"%-010d\"",
	"\"% +-10d\"",
	"\"% +010d\"",
	"\"% -010d\"",
	"\"%+-010d\"",
	"\"% +-010d\"",
	NULL
};

int	test(t_printf f)
{
	const char	**fmt;

	f("%+042d\n", 42);
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
