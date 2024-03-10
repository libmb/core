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
	result->exponent = exponent;
	result->max_iteration_count = max_iteration_count;
	*out = result;
	return (false);
}
