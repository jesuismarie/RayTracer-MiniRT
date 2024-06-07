/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:42:00 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/07 13:08:05 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	solve_cone(t_vector pos, t_vector ray, t_figure **obj, \
	t_equition *dot)
{
	double		dot_v;
	double		dot_u;
	t_vector	v;
	t_vector	u;
	t_vector	vec;

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

static int	solve_caps(t_vector pos, t_vector ray, t_vector center, \
	t_figure **obj)
{
	t_equition	dot;
	t_vector	surf;

	dot.x1 = caps_intersection(pos, ray, \
		(*obj)->cone->axis, center);
	if (dot.x1 == -1)
		return (0);
	(*obj)->point.dist = dot.x1;
	if ((*obj)->point.dist > 0)
	{
		(*obj)->point.hit_pos = vector_sum(pos, vector_prod(ray, \
			(*obj)->point.dist));
		surf = vector_sub((*obj)->point.hit_pos, center);
		if (vector_scalar_prod(surf, surf) <= pow((*obj)->cone->radius, 2))
		{
			(*obj)->cone->cap = 1;
			return (1);
		}
	}
	return (0);
}

double	cone_intersection(t_vector pos, t_vector ray, t_figure **obj)
{
	double		hypotenuse;
	t_vector	center;
	t_equition	dot;

	(*obj)->point.dist = 0;
	hypotenuse = sqrt(pow((*obj)->cone->radius, 2) \
		+ pow((*obj)->cone->height, 2));
	(*obj)->cone->cos = (*obj)->cone->height / hypotenuse;
	(*obj)->cone->sin = (*obj)->cone->radius / hypotenuse;
	solve_cone(pos, ray, obj, &dot);
	(*obj)->cone->cap = 0;
	center = vector_sum((*obj)->cone->apex, \
		vector_prod((*obj)->cone->axis, (*obj)->cone->height));
	(*obj)->point.hit_pos = vector_sum(pos, vector_prod(ray, \
		(*obj)->point.dist));
	dot.m1 = vector_scalar_prod((*obj)->cone->axis, \
		vector_sub((*obj)->point.hit_pos, (*obj)->cone->apex));
	dot.m2 = vector_scalar_prod((*obj)->cone->axis, \
		vector_sub((*obj)->point.hit_pos, center));
	if (dot.m1 > 0 && dot.m2 < 0)
		return ((*obj)->point.dist);
	if (solve_caps(pos, ray, center, obj))
		return ((*obj)->point.dist);
	return (0);
}
