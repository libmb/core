/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_core_type.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:34:31 by jmaing            #+#    #+#             */
/*   Updated: 2024/03/11 22:50:21 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MB_CORE_TYPE_H
# define MB_CORE_TYPE_H

# include <stdbool.h>

# include "mb_rt_type.h"

typedef bool				t_err;

typedef struct s_mb_real	t_mb_real;

typedef void				(*t_mb_real_v_delete)(
								t_mb_real *self);

typedef t_err				(*t_mb_real_v_clone)(
								t_mb_real *self,
								t_mb_real **out);

typedef t_err				(*t_mb_real_v_assign)(
								t_mb_real **lhs,
								t_mb_real *rhs);

typedef t_err				(*t_mb_real_v_binary)(
								t_mb_real *lhs,
								t_mb_real *rhs,
								t_mb_real **out);

typedef t_err				(*t_mb_real_v_check)(
								t_mb_real *self,
								bool *out);

typedef t_err				(*t_mb_real_v_to_float)(
								t_mb_real *self,
								float *out);

typedef t_err				(*t_mb_real_v_from_float)(
								float value,
								t_mb_real **out);

typedef struct s_mb_real_type
{
	t_mb_real_v_delete	delete;
	t_mb_real_v_clone	clone;
	t_mb_real_v_binary	add;
	t_mb_real_v_binary	multiply;
	t_mb_real_v_assign	assign;
	t_mb_real_v_assign	assign_add;
	t_mb_real_v_assign	assign_multiply;
	t_mb_real_v_check	is_greater_than_or_equal_to_two;
}	t_mb_real_type;

typedef struct s_mb			t_mb;

#endif
