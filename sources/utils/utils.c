/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:21:41 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/09 19:56:16 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	find_hit_distance(t_figure **obj, t_equation dot)
{
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
}

double	caps_intersection(t_vector pos, t_vector ray, t_vector norm, \
	t_vector center)
{
	double		dist;
	double		dot;
	t_vector	vec;

	dist = 0;
	dot = vector_scalar_prod(norm, ray);
	if (fabs(dot) < __FLT_EPSILON__)
		return (INFINITY);
	vec = vector_sub(center, pos);
	dist = vector_scalar_prod(norm, vec) / dot;
	if (dist < __FLT_EPSILON__)
		return (INFINITY);
	return (dist);
}

t_vector	reflect_ray(t_vector ray, t_vector norm)
{
	t_vector	reflected;

	reflected = vector_prod(norm, 2 * vector_scalar_prod(ray, norm));
	reflected = vector_sub(reflected, ray);
	return (reflected);
}
