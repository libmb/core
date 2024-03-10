/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_rt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:53:41 by jmaing            #+#    #+#             */
/*   Updated: 2024/03/10 22:31:38 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MB_RT_H
# define MB_RT_H

# include "mb_rt_type.h"

t_err					mb_rt_buffer_read_from_file(
							const char *file_name,
							t_mb_rt_buffer *out);
t_err					mb_rt_buffer_merge(
							size_t count,
							const t_mb_rt_buffer *buffers,
							t_mb_rt_buffer *out);

t_mb_rt_buffer_builder	*mb_rt_buffer_builder_new(void);
t_err					mb_rt_buffer_builder_append(
							t_mb_rt_buffer_builder *self,
							t_mb_rt_buffer buffer);
void					mb_rt_buffer_builder_build(
							t_mb_rt_buffer_builder *self,
							t_mb_rt_buffer *out);
void					mb_rt_buffer_builder_delete(
							t_mb_rt_buffer_builder *self);

t_mb_rt_stack			*mb_rt_stack(void);

t_err					mb_rt_stack_ok(t_mb_rt_stack *self);
t_err					mb_rt_stack_ko(t_mb_rt_stack *self);
t_err					mb_rt_stack_add(
							t_mb_rt_stack *self,
							t_mb_rt_resource *destination,
							t_mb_rt_resource resource);
t_err					mb_rt_stack_tmp(
							t_mb_rt_stack *self,
							t_mb_rt_resource *destination,
							t_mb_rt_resource resource);

#endif
