/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:03:16 by mnazarya          #+#    #+#             */
/*   Updated: 2024/04/04 21:19:56 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static float	find_hit_distance(t_figure **obj, t_equition dot)
{
	(*obj)->point.dist = 0;
	(*obj)->point.is_inside = 1;
	if (dot.x1 > __FLT_EPSILON__ || dot.x2 > __FLT_EPSILON__)
	{
		if (dot.x1 > __FLT_EPSILON__ && dot.x2 > __FLT_EPSILON__)
		{
			(*obj)->point.dist = fmin(dot.x1, dot.x2);
			(*obj)->point.is_inside = 0;
		}
		else if (dot.x1 > __FLT_EPSILON__)
			(*obj)->point.dist = dot.x1;
		else
			(*obj)->point.dist = dot.x2;
	}
	return ((*obj)->point.dist);
}

float	sphere_intersection(t_scene *scene, t_vector ray, t_figure **obj)
{
	t_equition	dot;
	t_vector	vec;

	vec = vector_sub(scene->cam->pos, (*obj)->sph->center);
	dot.a = vector_len(ray) * vector_len(ray);
	dot.b = 2 * vector_scalar_prod(vec, ray);
	dot.c = vector_len(vec) * vector_len(vec) - (*obj)->sph->radius \
		* (*obj)->sph->radius;
	dot.discr = (dot.b * dot.b) - (4 * dot.a * dot.c);
	if (dot.discr < 0)
		return (0);
	dot.x1 = ((dot.b * (-1)) - sqrt(dot.discr)) / (2 * dot.a);
	dot.x2 = ((dot.b * (-1)) + sqrt(dot.discr)) / (2 * dot.a);
	find_hit_distance(obj, dot);
	(*obj)->point.hit_pos = vector_sum(vector_prod(ray, (*obj)->point.dist), \
		scene->cam->pos);
	(*obj)->point.hit_norm = vector_sub((*obj)->point.hit_pos, \
		(*obj)->sph->center);
	normalize_vector(&(*obj)->point.hit_norm);
	// add spec, diffuse
	// (*obj)->color = multiply_rgbs((*obj)->color, (*obj)->point.rgb);
	return ((*obj)->point.dist);
}

	// --------------- intersection first version ---------------
	// dot.a = 1;
	// dot.b = 2 * vector_scalar_prod(vec, ray);
	// dot.c = vector_scalar_prod(vec, vec) - ((*obj)->sph->radius \
	// 	* (*obj)->sph->radius);
	// dot.x1 = ((dot.b * (-1)) - sqrt(dot.discr)) / (2 * dot.a);
	// dot.x2 = ((dot.b * (-1)) + sqrt(dot.discr)) / (2 * dot.a);
	// find_hit_distance(obj, dot);
	// (*obj)->point.hit_pos = vector_sub(vector_prod(ray, \
	// 	(*obj)->point.dist), (*obj)->sph->center);
	// normalize_vector(&(*obj)->point.hit_pos);
	// (*obj)->point.light_dir = vector_sub(scene->light->coordinate, \
	// 	vector_prod(ray, (*obj)->point.dist));
	// normalize_vector(&(*obj)->point.light_dir);