/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:11:59 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/09 18:47:04 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	solve_cylinder(t_vector pos, t_vector ray, t_figure **obj, \
	t_equation *dot)
{
	t_vector	v;
	t_vector	u;
	t_vector	vec;

	(*obj)->point.dist = 0;
	vec = vector_sub(pos, (*obj)->cyl->center);
	v = vector_sub(ray, vector_prod((*obj)->cyl->axis, \
		vector_scalar_prod((*obj)->cyl->axis, ray)));
	u = vector_sub(vec, vector_prod((*obj)->cyl->axis, \
		vector_scalar_prod((*obj)->cyl->axis, vec)));
	dot->a = vector_scalar_prod(v, v);
	dot->b = 2 * vector_scalar_prod(v, u);
	dot->c = vector_scalar_prod(u, u) - pow((*obj)->cyl->radius, 2);
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

	dist = 0;
	(*obj)->point.hit_pos = vector_sum(pos, vector_prod(ray, \
		(*obj)->point.dist));
	dot->m1 = vector_scalar_prod((*obj)->cyl->axis, \
		vector_sub((*obj)->point.hit_pos, (*obj)->cyl->center));
	dot->m2 = vector_scalar_prod((*obj)->cyl->axis, \
		vector_sub((*obj)->point.hit_pos, (*obj)->cyl->center1));
	if (dot->m1 > 0 && dot->m2 < 0)
		dist = (*obj)->point.dist;
	return (dist);
}

static int	solve_caps(t_vector pos, t_vector ray, t_figure **obj)
{
	t_vector	surf;
	t_equation	dot;

	dot.x1 = caps_intersection(pos, ray, (*obj)->cyl->axis, \
		(*obj)->cyl->center);
	dot.x2 = caps_intersection(pos, ray, (*obj)->cyl->axis, \
		(*obj)->cyl->center1);
	if (dot.x1 == INFINITY && dot.x2 == INFINITY)
		return (0);
	if (dot.x1 > dot.x2)
		(*obj)->cyl->flag = 1;
	find_hit_distance(obj, dot);
	(*obj)->point.hit_pos = vector_sum(pos, vector_prod(ray, \
		(*obj)->point.dist));
	surf = vector_sub((*obj)->point.hit_pos, (*obj)->cyl->center);
	if ((*obj)->cyl->flag)
		surf = vector_sub((*obj)->point.hit_pos, (*obj)->cyl->center1);
	if (vector_scalar_prod(surf, surf) < pow((*obj)->cyl->radius, 2))
	{
		(*obj)->cyl->cap = 1;
		return (1);
	}
	return (0);
}

double	cylinder_intersection(t_vector pos, t_vector ray, t_figure **obj)
{
	double		dist;
	t_equation	dot;

	(*obj)->cyl->cap = 0;
	(*obj)->cyl->flag = 0;
	solve_cylinder(pos, ray, obj, &dot);
	dist = check_caps(pos, ray, obj, &dot);
	if (solve_caps(pos, ray, obj))
	{
		if (dist && dist < (*obj)->point.dist && dot.m1 > 0 && dot.m2 < 0)
		{
			(*obj)->point.dist = dist;
			(*obj)->cyl->cap = 0;
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
