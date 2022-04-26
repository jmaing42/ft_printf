/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:02:59 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/26 21:35:44 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

#include <stdio.h>
#include <limits.h>
#include <stddef.h>

static const char	*g_minimum_field_width[] = {
	"",
	"0",
	"1",
	"2",
	"7",
	"8",
	"9",
	"10",
	"11",
	"12",
	"4095"
};

static const char	*g_precision[] = {
	"",
	".7",
	".8",
	".9",
	".10",
	".0",
	".",
	".100"
};

void	test_x(t_printf f)
{
	char	fmt[16];
	int		i;

	i = 0;
	while (i < (1 << 5) * 11)
	{
		sprintf(fmt, "\"%%%s%s%s%s%sx\"",
			o(i & 1, "-"), o(i & 2, "0"), o(i & 4, "#"),
			g_minimum_field_width[i >> 6], g_precision[(i >> 3) % 8]);
		f("Test for %%x - case #%d: %s {\n\tzero: ", i, fmt);
		f(fmt, 0);
		f(",\n\tpositive: ");
		f(fmt, 0x42424242);
		f(",\n\tmax: ");
		f(fmt, UINT_MAX);
		f(",\n} end case #%d (%s)\n\n", i, fmt);
		i++;
	}
}
