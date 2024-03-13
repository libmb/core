/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_core_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:25:04 by jmaing            #+#    #+#             */
/*   Updated: 2024/03/11 23:43:12 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MB_CORE_INTERNAL_H
# define MB_CORE_INTERNAL_H

# include "mb_core_type.h"

# include <stddef.h>

typedef struct s_mb_complex
{
	t_mb_real	*r;
	t_mb_real	*i;
}	t_mb_complex;

struct s_mb
{
	t_mb_real_type	type;
	size_t			exponent;
	size_t			max_iteration_count;
	t_mb_real		*x;
	t_mb_real		*y;
	t_mb_complex	z;
	t_mb_complex	t;
	t_mb_complex	n;
};

#endif
