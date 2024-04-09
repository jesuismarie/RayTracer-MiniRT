/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:11:59 by mnazarya          #+#    #+#             */
/*   Updated: 2024/04/02 14:47:36 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

float	cylinder_intersection(t_scene *scene, t_vector ray, t_figure **obj)
{
	t_equition	dot;
	t_vector	vec;
	float		norm_r;
	float		norm_c;

	vec = vector_sub(scene->cam->pos, (*obj)->cyl->center);
	normalize_vector(&(*obj)->cyl->axis);
	norm_r = vector_scalar_prod(ray, (*obj)->cyl->axis);
	norm_c = vector_scalar_prod(vec, (*obj)->cyl->axis);
	dot.a = vector_scalar_prod(ray, ray) - (norm_r * norm_r);
	dot.b = 2 * (vector_scalar_prod(ray, vec) - (norm_c * norm_r));
	dot.c = vector_scalar_prod(vec, vec) - norm_c * norm_r \
		- ((*obj)->cyl->radius * (*obj)->cyl->radius);
	dot.discr = (dot.b * dot.b) - (4 * dot.a * dot.c);
	if (dot.discr < 0)
		return (0);
	dot.x1 = ((dot.b * (-1)) - sqrt(dot.discr)) / (2 * dot.a);
	dot.x2 = ((dot.b * (-1)) + sqrt(dot.discr)) / (2 * dot.a);
	dot.m1 = vector_scalar_prod(ray, (*obj)->cyl->axis) * dot.x1 \
		- vector_scalar_prod(vec, (*obj)->cyl->axis);
	dot.m2 = vector_scalar_prod(ray, (*obj)->cyl->axis) * dot.x2 \
		- vector_scalar_prod(vec, (*obj)->cyl->axis);
	
	return (0);
}
