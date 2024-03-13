/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:47:22 by jmaing            #+#    #+#             */
/*   Updated: 2024/03/10 23:37:52 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mb_core.h"

#include <stdlib.h>

#include "mb_core_internal.h"

static t_err	cleanup(t_mb *resource, int phase)
{
	switch (phase)
	{
		case 7:
			resource->type.free(resource->type.context, resource->n.r);
		case 6:
			resource->type.free(resource->type.context, resource->t.i);
		case 5:
			resource->type.free(resource->type.context, resource->t.r);
		case 4:
			resource->type.free(resource->type.context, resource->z.i);
		case 3:
			resource->type.free(resource->type.context, resource->z.r);
		case 2:
			resource->type.free(resource->type.context, resource->y);
		case 1:
			resource->type.free(resource->type.context, resource->x);
		case 0:
			free(resource);
	}
	return (true);
}

t_err	mb_new(
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
		return (cleanup(result, 0));
	if (type.clone(type.context, type.zero, &result->y))
		return (cleanup(result, 1));
	if (type.clone(type.context, type.zero, &result->z.r))
		return (cleanup(result, 2));
	if (type.clone(type.context, type.zero, &result->z.i))
		return (cleanup(result, 3));
	if (type.clone(type.context, type.zero, &result->t.r))
		return (cleanup(result, 4));
	if (type.clone(type.context, type.zero, &result->t.i))
		return (cleanup(result, 5));
	if (type.clone(type.context, type.zero, &result->n.r))
		return (cleanup(result, 6));
	if (type.clone(type.context, type.zero, &result->n.i))
		return (cleanup(result, 7));
	result->exponent = exponent;
	result->max_iteration_count = max_iteration_count;
	*out = result;
	return (false);
}
