/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_core_type.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:34:31 by jmaing            #+#    #+#             */
/*   Updated: 2024/03/09 01:17:21 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MB_CORE_TYPE_H

# include <stdint.h>
# include <stdbool.h>

# include "mb_rt_type.h"

typedef bool								t_err;

typedef struct s_mb_real					t_mb_real;

typedef void								(*t_mb_real_v_delete)(
												t_mb_real *self);

typedef t_err								(*t_mb_real_v_clone)(
												t_mb_real *self,
												t_mb_real **out);

typedef t_err								(*t_mb_real_v_assign)(
												t_mb_real **lhs,
												t_mb_real *rhs);

typedef t_err								(*t_mb_real_v_binary)(
												t_mb_real *lhs,
												t_mb_real *rhs,
												t_mb_real **out);

typedef t_err								(*t_mb_real_v_check)(
												t_mb_real *self,
												bool *out);

typedef t_err								(*t_mb_real_v_relation)(
												t_mb_real *lhs,
												t_mb_real *rhs,
												bool *out);

typedef t_err								(*t_mb_real_v_to_string)(
												t_mb_real *self,
												char **out);

typedef t_err								(*t_mb_real_v_from_string)(
												char *string,
												t_mb_real **out);

typedef t_err								(*t_mb_real_v_to_float)(
												t_mb_real *self,
												float *out);

typedef t_err								(*t_mb_real_v_from_float)(
												float value,
												t_mb_real **out);

typedef t_err								(*t_mb_real_v_to_buffer)(
												t_mb_real *self,
												t_mb_rt_buffer *out);

typedef t_err								(*t_mb_real_v_from_buffer)(
												t_mb_rt_buffer buffer,
												t_mb_real **out);

typedef struct s_mb_real_type
{
	t_mb_real_v_delete		delete;
	t_mb_real_v_clone		clone;
	t_mb_real_v_binary		add;
	t_mb_real_v_binary		subtract;
	t_mb_real_v_binary		multiply;
	t_mb_real_v_binary		divide;
	t_mb_real_v_assign		assign;
	t_mb_real_v_assign		assign_add;
	t_mb_real_v_assign		assign_subtract;
	t_mb_real_v_assign		assign_multiply;
	t_mb_real_v_assign		assign_divide;
	t_mb_real_v_check		is_nan;
	t_mb_real_v_check		is_infinity;
	t_mb_real_v_relation	eq;
	t_mb_real_v_relation	greater;
	t_mb_real_v_relation	lesser;
	t_mb_real_v_to_string	to_string;
	t_mb_real_v_from_string	from_string;
	t_mb_real_v_to_float	to_float;
	t_mb_real_v_from_float	from_float;
	t_mb_real_v_to_buffer	to_buffer;
	t_mb_real_v_from_buffer	from_buffer;
}	t_mb_real_type;

typedef struct s_mb_color
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_mb_color;

typedef struct s_mb_color_palette_context	t_mb_color_palette_context;

typedef t_err								(*t_mb_color_palette_v_get)(
												t_mb_color_palette_context
												*context,
												uint_fast64_t iteration_count,
												t_mb_color *out);

typedef t_err								(*t_mb_color_palette_v_delete)(
												t_mb_color_palette_context
												*self);

typedef struct s_mb_color_palette
{
	t_mb_color_palette_context	*context;
	t_mb_color_palette_v_delete	delete;
	t_mb_color_palette_v_get	get;
}	t_mb_color_palette;

#endif
