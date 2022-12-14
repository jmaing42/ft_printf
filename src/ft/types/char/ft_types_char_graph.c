/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_char_graph.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 01:56:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/10 02:21:35 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types_char.h"

static const bool	g_t = true;
static const bool	g_f = false;

static const bool	g_map[256] = {
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0000 ~ 0007
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0010 ~ 0017
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0020 ~ 0027
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0030 ~ 0037
	g_f, g_t, g_t, g_t, g_t, g_t, g_t, g_t, // 0040 ~ 0047
	g_t, g_t, g_t, g_t, g_t, g_t, g_t, g_t, // 0050 ~ 0057
	g_t, g_t, g_t, g_t, g_t, g_t, g_t, g_t, // 0060 ~ 0067
	g_t, g_t, g_t, g_t, g_t, g_t, g_t, g_t, // 0070 ~ 0077
	g_t, g_t, g_t, g_t, g_t, g_t, g_t, g_t, // 0100 ~ 0107
	g_t, g_t, g_t, g_t, g_t, g_t, g_t, g_t, // 0110 ~ 0117
	g_t, g_t, g_t, g_t, g_t, g_t, g_t, g_t, // 0120 ~ 0127
	g_t, g_t, g_t, g_t, g_t, g_t, g_t, g_t, // 0130 ~ 0137
	g_t, g_t, g_t, g_t, g_t, g_t, g_t, g_t, // 0140 ~ 0147
	g_t, g_t, g_t, g_t, g_t, g_t, g_t, g_t, // 0150 ~ 0157
	g_t, g_t, g_t, g_t, g_t, g_t, g_t, g_t, // 0160 ~ 0167
	g_t, g_t, g_t, g_t, g_t, g_t, g_t, g_f, // 0170 ~ 0177
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0200 ~ 0207
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0210 ~ 0217
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0220 ~ 0227
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0230 ~ 0237
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0240 ~ 0247
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0250 ~ 0257
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0260 ~ 0267
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0270 ~ 0277
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0300 ~ 0307
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0310 ~ 0317
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0320 ~ 0327
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0330 ~ 0337
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0340 ~ 0347
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0350 ~ 0357
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0360 ~ 0367
	g_f, g_f, g_f, g_f, g_f, g_f, g_f, g_f, // 0370 ~ 0377
};

bool	ft_types_char_graph(char c)
{
	return (g_map[(unsigned char)c]);
}
