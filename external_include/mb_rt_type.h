/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_rt_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:23:30 by jmaing            #+#    #+#             */
/*   Updated: 2024/03/10 22:31:36 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MB_RT_TYPE_H
# define MB_RT_TYPE_H

# include <stddef.h>
# include <stdbool.h>

typedef bool					t_err;

typedef struct s_mb_rt_buffer {
	void	*buffer;
	size_t	length;
}	t_mb_rt_buffer;

typedef struct s_mb_rt_buffer_builder {
	void	*buffer;
	size_t	length;
	size_t	capacity;
}	t_mb_rt_buffer_builder;

typedef struct s_mb_rt_stack	t_mb_rt_stack;

typedef struct s_mb_rt_resource
{
	void	*data;
	void	(*cleanup)(void *data);
}	t_mb_rt_resource;

typedef t_err					(*t_mb_rt_stack_v_end)(
									t_mb_rt_stack *self);
typedef t_err					(*t_mb_rt_stack_v_add)(
									t_mb_rt_stack *self,
									t_mb_rt_resource *destination,
									t_mb_rt_resource resource);

typedef struct s_mb_rt_stack_v
{
	t_mb_rt_stack_v_end	ko;
	t_mb_rt_stack_v_end	ok;
	t_mb_rt_stack_v_add	add;
	t_mb_rt_stack_v_add	tmp;
}	t_mb_rt_stack_v;

struct s_mb_rt_stack
{
	t_mb_rt_stack_v	*v;
	char			extra[];
};

#endif
