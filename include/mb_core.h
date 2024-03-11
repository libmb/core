/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_core.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:36:03 by jmaing            #+#    #+#             */
/*   Updated: 2024/03/11 23:50:20 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MB_CORE_H
# define MB_CORE_H

# include <stddef.h>

# include "mb_core_type.h"

t_err	mb_new(
			t_mb_real_type type,
			size_t exponent,
			size_t max_iteration_count,
			t_mb **out);
t_err	mb(
			t_mb *context,
			t_mb_real *real,
			t_mb_real *imaginary,
			size_t *out);
void	mb_delete(t_mb *self);

#endif
