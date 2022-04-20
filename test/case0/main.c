/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:53:00 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/20 17:59:23 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../../src/format.h"

int	main(void)
{
	t_printf_format	*format;

	format = printf_format_parse("Hello %s!");
	if (format)
		printf_format_free(format);
	return (0);
}
