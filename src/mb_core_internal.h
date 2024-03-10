/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_core_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:25:04 by jmaing            #+#    #+#             */
/*   Updated: 2024/03/10 23:45:02 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MB_CORE_INTERNAL_H
# define MB_CORE_INTERNAL_H

# include "mb_rt_type.h"
# include "mb_core_type.h"

struct s_mb
{
	t_mb_real_type	type;
	size_t			exponent;
	size_t			max_iteration_count;
};

#endif
