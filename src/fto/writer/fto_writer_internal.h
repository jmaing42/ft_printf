/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fto_writer_internal.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:56:38 by jmaing            #+#    #+#             */
/*   Updated: 2022/07/25 00:35:25 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTO_WRITER_INTERNAL_H
# define FTO_WRITER_INTERNAL_H

# include "fto_writer.h"

t_err	ft_writer_base_v_default_close(
			t_writer *self,
			t_exception **exception);

t_err	ft_writer_base_v_default_flush(
			t_writer *self,
			t_exception **exception);

#endif
