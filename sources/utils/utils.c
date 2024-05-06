/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:21:41 by mnazarya          #+#    #+#             */
/*   Updated: 2024/05/06 15:25:06 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	set_hit_normal(t_figure **obj, t_vector ray)
{
	if ((*obj)->type == SPHERE)
		(*obj)->point.hit_norm = vector_sub((*obj)->point.hit_pos, \
			(*obj)->sph->center);
	else if ((*obj)->type == PLANE)
	{
		if (vector_scalar_prod((*obj)->pln->norm, ray) < 0)
			(*obj)->point.hit_norm = (*obj)->pln->norm;
		else
			(*obj)->point.hit_norm = vector_prod((*obj)->pln->norm, -1);
	}
	normalize_vector(&(*obj)->point.hit_norm);
}
