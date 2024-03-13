/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:59:56 by jmaing            #+#    #+#             */
/*   Updated: 2024/03/10 23:44:45 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mb_core.h"

#include <stdlib.h>

#include "mb_core_internal.h"

static void	ok(t_err err)
{
	if (err)
		exit(EXIT_FAILURE);
}

t_err	mb(
	const t_mb *context,
	const t_mb_real *c_r,
	const t_mb_real *c_i,
	size_t *out
)
{
	t_mb_real	*tmp1;
	t_mb_real	*tmp2;
	t_mb_real	*z_r;
	t_mb_real	*z_i;
	t_mb_real	*t_r;
	t_mb_real	*t_i;
	t_mb_real	*n_r;
	t_mb_real	*n_i;
	size_t		i;
	size_t		j;
	bool		test;

#define MB_OP(op, ...) do { ok(context->type.op(context->type.context, __VA_ARGS__)); } while (0)
#define MB_INITIALIZE_REAL(varname) do { MB_OP(clone, context->type.zero, &varname); } while (0)
	MB_INITIALIZE_REAL(tmp1);
	MB_INITIALIZE_REAL(tmp2);
#define MB_INITIALIZE_COMPLEX(varname) do { MB_INITIALIZE_REAL(varname ## _r); MB_INITIALIZE_REAL(varname ## _i); } while (0)
	MB_INITIALIZE_COMPLEX(z);
	MB_INITIALIZE_COMPLEX(t);
	MB_INITIALIZE_COMPLEX(n);
#undef MB_INITIALIZE_COMPLEX
#undef MB_INITIALIZE_REAL
#define MB_COMPLEX_ADD(c, a, b) do { MB_OP(add, &(c ## _r), a ## _r, b ## _r); MB_OP(add, &(c ## _i), a ## _i, b ## _i); } while (0)
#define MB_COMPLEX_MULTIPLY(c, a, b) do { MB_OP(multiply, &tmp1, a ## _r, b ## _r); MB_OP(multiply, &tmp2, a ## _i, b ## _i); MB_OP(negate, &tmp2); MB_OP(add, &(c ## _r), tmp1, tmp2); MB_OP(multiply, &tmp1, a ## _r, b ## _i); MB_OP(multiply, &tmp2, a ## _i, b ## _r); MB_OP(add, &(c ## _i), tmp1, tmp2); } while (0)
#define MB_COMPLEX_ASSIGN(b, a) do { MB_OP(assign, &(b ## _r), a ## _r); MB_OP(assign, &(b ## _i), a ## _i); } while (0)
#define MB_SWAP(a, b) do { t_mb_real *tmp = a; a = b; b = tmp; } while (0)
#define MB_SWAP_COMPLEX(a, b) do { MB_SWAP(a ## _r, b ## _r); MB_SWAP(a ## _i, b ## _i); } while (0)
	i = (size_t)-1;
	while (++i < context->max_iteration_count)
	{
		j = context->exponent;
		MB_COMPLEX_ASSIGN(t, z);
		MB_OP(assign, &z_r, context->type.one);
		MB_OP(assign, &z_i, context->type.zero);
		while (j)
		{
			if (j & 1)
			{
				MB_COMPLEX_MULTIPLY(n, z, t);
				MB_SWAP_COMPLEX(z, n);
			}
			MB_COMPLEX_MULTIPLY(n, t, t);
			MB_SWAP_COMPLEX(t, n);
			j >>= 2;
		}
		MB_COMPLEX_ADD(n, z, c);
		MB_SWAP_COMPLEX(z, n);
		MB_OP(multiply, &tmp1, z_r, z_r);
		MB_OP(multiply, &tmp2, z_i, z_i);
		MB_OP(add, &n_r, tmp1, tmp2);
		MB_OP(is_greater_than_or_equal_to_four, n_r, &test);
		if (test)
			break;
	}
	*out = i;
	return (false);
#undef MB_SWAP_COMPLEX
#undef MB_SWAP
#undef MB_COMPLEX_ASSIGN
#undef MB_COMPLEX_MULTIPLY
#undef MB_COMPLEX_ADD
#undef MB_OP
}
