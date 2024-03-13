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

static void swap2(t_mb_real **a, t_mb_real **b, t_mb_real **c, t_mb_real **d)
{
	t_mb_real *tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
    tmp = *c;
    *c = *d;
    *d = tmp;
}

static t_err	complex_multiply(
	t_mb *context,
	t_mb_complex *result,
	t_mb_complex lhs,
	t_mb_complex rhs
)
{
	const t_mb_real_type	t = context->type;
	void *const				c = context->type.context;

	return (
		false
		|| t.mul(c, &context->x, lhs.r, rhs.r)
		|| t.mul(c, &context->y, lhs.i, rhs.i)
		|| t.negate(c, &context->y)
		|| t.add(c, &result->r, context->x, context->y)
		|| t.mul(c, &context->x, lhs.r, rhs.i)
		|| t.mul(c, &context->y, lhs.i, rhs.r)
		|| t.add(c, &result->i, context->x, context->y)
	);
}

t_err	mb(
	t_mb *s,
	const t_mb_real *c_r,
	const t_mb_real *c_i,
	size_t *out
)
{
	size_t					i;
	size_t					j;
	bool					b;
	const t_mb_real_type	t = s->type;
	void *const				c = s->type.context;

	i = (size_t)-1;
	while (++i < s->max_iteration_count)
	{
		j = s->exponent;
		swap2(&s->t.r, &s->z.r, &s->t.i, &s->z.i);
		if (t.assign(c, &s->z.r, t.one) || t.assign(c, &s->z.i, t.zero))
			return (true);
		while (j)
		{
			if (j & 1)
			{
				if (complex_multiply(s, &s->n, s->z, s->t))
					return (true);
				swap2(&s->z.r, &s->n.r, &s->z.i, &s->n.i);
			}
			if (complex_multiply(s, &s->n, s->t, s->t))
				return (true);
			swap2(&s->t.r, &s->n.r, &s->t.i, &s->n.i);
			j >>= 2;
		}
		if (t.add(c, &s->n.i, s->z.i, c_i) || t.add(c, &s->n.r, s->z.r, c_r))
			return (true);
		swap2(&s->z.r, &s->n.r, &s->z.i, &s->n.i);
		if (t.mul(c, &s->x, s->z.r, s->z.r) || t.mul(c, &s->y,s->z.i, s->z.i)
			|| t.add(c, &s->n.r, s->x, s->y) || t.is_ge4(c, s->n.r, &b))
			return (true);
		if (b)
			break;
	}
	*out = i;
	return (false);
}
