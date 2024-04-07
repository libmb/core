/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_core_type.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:34:31 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/04/08 02:19:28 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MB_CORE_TYPE_H
# define MB_CORE_TYPE_H

# include <stdbool.h>

# ifndef MB_ERR_DEFINED
#  define MB_ERR_DEFINED

typedef bool				t_mb_err;

# endif

typedef struct s_mb_real	t_mb_real;

typedef void				(*t_mb_real_v_free)(
								void *context,
								t_mb_real *self);

typedef t_mb_err			(*t_mb_real_v_clone)(
								void *context,
								const t_mb_real *self,
								t_mb_real **out);

typedef t_mb_err			(*t_mb_real_v_assign)(
								void *context,
								t_mb_real **self,
								const t_mb_real *other);

typedef t_mb_err			(*t_mb_real_v_binary)(
								void *context,
								t_mb_real **mut,
								const t_mb_real *lhs,
								const t_mb_real *rhs);

typedef t_mb_err			(*t_mb_real_v_negate)(
								void *context,
								t_mb_real **self);

typedef t_mb_err			(*t_mb_real_v_check)(
								void *context,
								const t_mb_real *self,
								bool *out);

typedef struct s_mb_real_type
{
	void				*context;
	t_mb_real_v_free	free;
	t_mb_real_v_clone	clone;
	t_mb_real_v_assign	assign;
	t_mb_real_v_binary	add;
	t_mb_real_v_binary	mul;
	t_mb_real_v_negate	negate;
	t_mb_real_v_check	is_ge4;
	const t_mb_real		*zero;
	const t_mb_real		*one;
}	t_mb_real_type;

typedef struct s_mb			t_mb;

#endif
