/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:21:41 by mnazarya          #+#    #+#             */
/*   Updated: 2024/05/21 20:11:18 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	set_hit_normal(t_figure **obj, t_vector ray)
{
	t_vector	vec;

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
	else if ((*obj)->type == CYLINDER)
	{
		(*obj)->point.hit_norm = vector_sub((*obj)->point.hit_pos, \
			(*obj)->cyl->center);
	}
	else if ((*obj)->type == CONE)
	{
		vec = vector_sub((*obj)->point.hit_pos, (*obj)->cone->apex);
		(*obj)->point.hit_norm = vector_sub(vec, \
			vector_prod((*obj)->cone->axis, vector_scalar_prod(vec, \
				(*obj)->cone->axis)));
	}
	normalize_vector(&(*obj)->point.hit_norm);
}

t_vector	reflect_ray(t_vector ray, t_vector norm)
{
	t_vector	reflected;

	reflected = vector_prod(norm, 2 * vector_scalar_prod(ray, norm));
	reflected = vector_sub(reflected, ray);
	return (reflected);
}
