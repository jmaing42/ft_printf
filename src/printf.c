/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:42:53 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/18 17:46:23 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

#include "libftprintf.h"
#include "util.h"

int	ft_printf(const char *format, ...)
{
	va_list	arguments_n;
	va_list	arguments_s;
	size_t	length;
	char	*tmp;
	int		result;

	va_start(arguments_s, format);
	va_copy(arguments_n, arguments_s);
	length = ft_vnprintf(format, arguments_n);
	va_end(arguments_n);
	tmp = NULL;
	result = -1;
	if (length <= INT_MAX)
	{
		tmp = (char *) malloc(length + 1);
		if (tmp)
		{
			ft_vsprintf(tmp, format, arguments_s);
			if (!ft_fwrite(1, tmp, length, NULL))
				result = length;
		}
	}
	free(tmp);
	va_end(arguments_s);
	return (result);
}
