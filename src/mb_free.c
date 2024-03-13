/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:56:24 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2024/03/14 00:22:39 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mb_core.h"

#include <stdlib.h>

#include "mb_core_internal.h"

void	mb_free(t_mb *self)
{
	self->type.free(self->type.context, self->x);
	self->type.free(self->type.context, self->y);
	self->type.free(self->type.context, self->z.r);
	self->type.free(self->type.context, self->z.i);
	self->type.free(self->type.context, self->t.r);
	self->type.free(self->type.context, self->t.i);
	self->type.free(self->type.context, self->n.r);
	self->type.free(self->type.context, self->n.i);
	free(self);
}
