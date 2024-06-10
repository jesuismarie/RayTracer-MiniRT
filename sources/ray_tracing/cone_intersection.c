/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:42:00 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/10 13:09:02 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	solve_cone(t_vector pos, t_vector ray, t_figure **obj, \
	t_equation *dot)
{
	double		dot_v;
	double		dot_u;
	t_vector	v;
	t_vector	u;
	t_vector	vec;

	(*obj)->point.dist = 0;
	vec = vector_sub(pos, (*obj)->cone->apex);
	dot_v = vector_scalar_prod((*obj)->cone->axis, ray);
	dot_u = vector_scalar_prod((*obj)->cone->axis, vec);
	v = vector_sub(ray, vector_prod((*obj)->cone->axis, dot_v));
	u = vector_sub(vec, vector_prod((*obj)->cone->axis, dot_u));
	dot->a = pow((*obj)->cone->cos, 2) * vector_scalar_prod(v, v) \
		- pow((*obj)->cone->sin, 2) * pow(dot_v, 2);
	dot->b = 2 * (pow((*obj)->cone->cos, 2) * vector_scalar_prod(v, u)) \
		- 2 * pow((*obj)->cone->sin, 2) * dot_v * dot_u;
	dot->c = pow((*obj)->cone->cos, 2) * vector_scalar_prod(u, u) \
		- pow((*obj)->cone->sin, 2) * pow(dot_u, 2);
	dot->discr = pow(dot->b, 2) - 4 * dot->a * dot->c;
	if (dot->discr < 0)
		return ;
	dot->x1 = ((dot->b * (-1)) - sqrt(dot->discr)) / (2 * dot->a);
	dot->x2 = ((dot->b * (-1)) + sqrt(dot->discr)) / (2 * dot->a);
	find_hit_distance(obj, *dot);
}

static double	check_caps(t_vector pos, t_vector ray, t_figure **obj, \
	t_equation *dot)
{
	double	dist;

	dist = INFINITY;
	solve_cone(pos, ray, obj, dot);
	(*obj)->point.hit_pos = vector_sum(pos, vector_prod(ray, \
		(*obj)->point.dist));
	dot->m1 = vector_scalar_prod((*obj)->cone->axis, \
		vector_sub((*obj)->point.hit_pos, (*obj)->cone->center));
	dot->m2 = vector_scalar_prod((*obj)->cone->axis, \
		vector_sub((*obj)->point.hit_pos, (*obj)->cone->apex));
	if (dot->m1 > 0 && dot->m2 < 0)
		dist = (*obj)->point.dist;
	return (dist);
}

static int	solve_caps(t_vector pos, t_vector ray, t_figure **obj)
{
	t_equation	dot;
	t_vector	surf;

	dot.x1 = caps_intersection(pos, ray, (*obj)->cone->axis, \
		(*obj)->cone->center);
	if (dot.x1 == INFINITY)
		return (0);
	(*obj)->point.dist = dot.x1;
	(*obj)->point.hit_pos = vector_sum(pos, vector_prod(ray, \
		(*obj)->point.dist));
	surf = vector_sub((*obj)->point.hit_pos, (*obj)->cone->center);
	if (vector_scalar_prod(surf, surf) <= pow((*obj)->cone->radius, 2))
	{
		(*obj)->cone->cap = 1;
		return (1);
	}
	return (0);
}

double	cone_intersection(t_vector pos, t_vector ray, t_figure **obj)
{
	double		dist;
	t_equation	dot;

	(*obj)->cone->cap = 0;
	dist = check_caps(pos, ray, obj, &dot);
	if (solve_caps(pos, ray, obj))
	{
		if (dist && dist < (*obj)->point.dist && dot.m1 > 0 && dot.m2 < 0)
		{
			(*obj)->point.dist = dist;
			(*obj)->cone->cap = 0;
		}
		return ((*obj)->point.dist);
	}
	if (dot.m1 > 0 && dot.m2 < 0)
	{
		(*obj)->point.dist = dist;
		(*obj)->point.hit_pos = vector_sum(pos, vector_prod(ray, \
			(*obj)->point.dist));
		return ((*obj)->point.dist);
	}
	return (INFINITY);
}
