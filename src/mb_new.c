/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:47:22 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/04/08 02:20:21 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mb_core.h"

#include <stdlib.h>

#include "mb_core_internal.h"

static void	cleanup2(t_mb *r, int phase)
{
	r->type.free(r->type.context, r->z.i);
	if (phase >= 3)
	{
		r->type.free(r->type.context, r->z.r);
		if (phase >= 2)
		{
			r->type.free(r->type.context, r->y);
			if (phase >= 1)
			{
				r->type.free(r->type.context, r->x);
				if (phase >= 0)
					free(r);
			}
		}
	}
}

static t_mb_err	cleanup1(t_mb *r, int phase)
{
	if (phase >= 7)
	{
		r->type.free(r->type.context, r->n.r);
		if (phase >= 6)
		{
			r->type.free(r->type.context, r->t.i);
			if (phase >= 5)
			{
				r->type.free(r->type.context, r->t.r);
				if (phase >= 4)
					cleanup2(r, phase);
			}
		}
	}
	return (true);
}

t_mb_err	mb_new(
	t_mb_real_type type,
	size_t exponent,
	size_t max_iteration_count,
	t_mb **out
)
{
	t_mb *const	result = malloc(sizeof(t_mb));

	if (!result)
		return (true);
	result->type = type;
	if (type.clone(type.context, type.zero, &result->x))
		return (cleanup1(result, 0));
	if (type.clone(type.context, type.zero, &result->y))
		return (cleanup1(result, 1));
	if (type.clone(type.context, type.zero, &result->z.r))
		return (cleanup1(result, 2));
	if (type.clone(type.context, type.zero, &result->z.i))
		return (cleanup1(result, 3));
	if (type.clone(type.context, type.zero, &result->t.r))
		return (cleanup1(result, 4));
	if (type.clone(type.context, type.zero, &result->t.i))
		return (cleanup1(result, 5));
	if (type.clone(type.context, type.zero, &result->n.r))
		return (cleanup1(result, 6));
	if (type.clone(type.context, type.zero, &result->n.i))
		return (cleanup1(result, 7));
	result->exponent = exponent;
	result->max_iteration_count = max_iteration_count;
	*out = result;
	return (false);
}
