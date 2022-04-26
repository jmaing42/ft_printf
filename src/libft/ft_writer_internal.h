/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:56:38 by jmaing            #+#    #+#             */
/*   Updated: 2022/04/26 23:27:58 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WRITER_INTERNAL_H
# define FT_WRITER_INTERNAL_H

# include "ft_writer.h"

t_err	ft_writer_base_v_default_close(
			t_writer *self,
			t_exception **exception);

t_err	ft_writer_base_v_default_flush(
			t_writer *self,
			t_exception **exception);

#endif
