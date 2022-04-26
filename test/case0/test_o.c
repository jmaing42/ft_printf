/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:02:59 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/26 20:40:35 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

#include <stdio.h>
#include <limits.h>
#include <stddef.h>

static const char	*minimum_field_width[] = {
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

static const char	*precision[] = {
	"",
	".7",
	".8",
	".9",
	".10",
	".0",
	".",
	".100"
};

void	test_o(t_printf f)
{
	char	fmt[17];
	int		i;

	i = 0;
	while (i < (1 << 6) * 11)
	{
		sprintf(fmt, "\"%%%s%s%s%s%so\"",
			i & 1 ? "-" : "", i & 2 ? "0" : "", i & 2 ? "#" : "",
			minimum_field_width[i >> 6], precision[(i >> 3) % 8]);
		f("Test for %%o - case #%d: %s {\n\tzero: ", i, fmt);
		f(fmt, 0);
		f(",\n\t9054370: ");
		f(fmt, 042424242);
		f(",\n\tmax: ");
		f(fmt, UINT_MAX);
		f(",\n} end case #%d (%s)\n\n", i, fmt);
		i++;
	}
}
