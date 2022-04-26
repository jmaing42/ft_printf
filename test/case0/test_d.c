/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:02:59 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/26 21:02:56 by jmaing           ###   ########.fr       */
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

void	test_d(t_printf f)
{
	char	fmt[17];
	int		i;

	i = 0;
	while (i < (1 << 7) * 11)
	{
		sprintf(fmt, "\"%%%s%s%s%s%s%sd\"",
			o(i & 1, "-"), o(i & 2, "0"), o(i & 4, "+"), o(i & 8, " "),
			g_minimum_field_width[i >> 7], g_precision[(i >> 4) % 8]);
		f("Test for %%d - case #%d: %s {\n\tzero: ", i, fmt);
		f(fmt, 0);
		f(",\n\tpositive: ");
		f(fmt, 42424242);
		f(",\n\tnegative: ");
		f(fmt, -42424242);
		f(",\n\tmax: ");
		f(fmt, INT_MAX);
		f(",\n\tmin: ");
		f(fmt, INT_MIN);
		f(",\n} end case #%d (%s)\n\n", i, fmt);
		i++;
	}
}

void	test_i(t_printf f)
{
	char	fmt[17];
	int		i;

	i = 0;
	while (i < (1 << 7) * 11)
	{
		sprintf(fmt, "\"%%%s%s%s%s%s%si\"",
			o(i & 1, "-"), o(i & 2, "0"), o(i & 4, "+"), o(i & 8, " "),
			g_minimum_field_width[i >> 7], g_precision[(i >> 4) % 8]);
		f("Test for %%i - case #%d: %s {\n\tzero: ", i, fmt);
		f(fmt, 0);
		f(",\n\tpositive: ");
		f(fmt, 42424242);
		f(",\n\tnegative: ");
		f(fmt, -42424242);
		f(",\n\tmax: ");
		f(fmt, INT_MAX);
		f(",\n\tmin: ");
		f(fmt, INT_MIN);
		f(",\n} end case #%d (%s)\n\n", i, fmt);
		i++;
	}
}
