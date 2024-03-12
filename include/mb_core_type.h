/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_core_type.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:34:31 by jmaing            #+#    #+#             */
/*   Updated: 2024/03/12 00:31:04 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MB_CORE_TYPE_H
# define MB_CORE_TYPE_H

# include <stdbool.h>

typedef bool				t_err;

typedef struct s_mb_real	t_mb_real;

typedef void				(*t_mb_real_v_free)(
								void *context,
								t_mb_real *self);

typedef t_err				(*t_mb_real_v_clone)(
								void *context,
								t_mb_real *self,
								t_mb_real **out);

typedef t_err				(*t_mb_real_v_assign)(
								void *context,
								t_mb_real **self,
								t_mb_real *other);

typedef t_err				(*t_mb_real_v_binary)(
								void *context,
								t_mb_real **mut,
								t_mb_real *lhs,
								t_mb_real *rhs);

typedef t_err				(*t_mb_real_v_negate)(
								void *context,
								t_mb_real **self);

typedef t_err				(*t_mb_real_v_check)(
								void *context,
								t_mb_real *self,
								bool *out);

typedef struct s_mb_real_type
{
	void				*context;
	t_mb_real_v_free	free;
	t_mb_real_v_clone	clone;
	t_mb_real_v_assign	assign;
	t_mb_real_v_binary	add;
	t_mb_real_v_binary	multiply;
	t_mb_real_v_negate	negate;
	t_mb_real_v_check	is_greater_than_or_equal_to_four;
	t_mb_real			*zero;
	t_mb_real			*one;
}	t_mb_real_type;

typedef struct s_mb			t_mb;

#endif
