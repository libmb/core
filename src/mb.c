/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:59:56 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/03/14 00:22:39 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mb_core.h"

#include "mb_core_internal.h"

static void	complex_swap(t_mb_complex *a, t_mb_complex *b)
{
	t_mb_real	*tmp;

	tmp = a->r;
	a->r = b->r;
	b->r = tmp;
	tmp = a->i;
	a->i = b->i;
	b->i = tmp;
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

static t_err	z_eq_z_pow_e(t_mb *s)
{
	const t_mb_real_type	t = s->type;
	void *const				c = s->type.context;
	size_t					e;

	complex_swap(&s->t, &s->z);
	if (t.assign(c, &s->z.r, t.one) || t.assign(c, &s->z.i, t.zero))
		return (true);
	e = s->exponent;
	while (e)
	{
		if (e & 1)
		{
			if (complex_multiply(s, &s->n, s->z, s->t))
				return (true);
			complex_swap(&s->z, &s->n);
		}
		if (complex_multiply(s, &s->n, s->t, s->t))
			return (true);
		complex_swap(&s->t, &s->n);
		e >>= 1;
	}
	return (false);
}

static t_err	z_eq_z_plus_c(
	t_mb *s,
	const t_mb_real *c_r,
	const t_mb_real *c_i
)
{
	const t_mb_real_type	t = s->type;
	void *const				c = s->type.context;

	if (t.add(c, &s->n.i, s->z.i, c_i) || t.add(c, &s->n.r, s->z.r, c_r))
		return (true);
	complex_swap(&s->z, &s->n);
	return (false);
}

t_err	mb(
	t_mb *s,
	const t_mb_real *real,
	const t_mb_real *imaginary,
	size_t *out
)
{
	size_t					i;
	bool					b;
	const t_mb_real_type	t = s->type;
	void *const				c = s->type.context;

	if (false
		|| t.assign(c, &s->z.r, t.zero)
		|| t.assign(c, &s->z.i, t.zero))
		return (true);
	i = (size_t)-1;
	while (++i < s->max_iteration_count)
	{
		if (false
			|| z_eq_z_pow_e(s)
			|| z_eq_z_plus_c(s, real, imaginary)
			|| t.mul(c, &s->x, s->z.r, s->z.r)
			|| t.mul(c, &s->y, s->z.i, s->z.i)
			|| t.add(c, &s->n.r, s->x, s->y)
			|| t.is_ge4(c, s->n.r, &b))
			return (true);
		if (b)
			break ;
	}
	*out = i;
	return (false);
}
