/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:11:59 by mnazarya          #+#    #+#             */
/*   Updated: 2024/05/14 20:55:07 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	find_hit_distance(t_figure **obj, t_equition dot)
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
}

static int	solve_cylinder(t_vector pos, t_vector ray, t_figure **obj, \
	t_equition *dot)
{
	t_vector	v;
	t_vector	u;
	t_vector	vec;

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
		return (0);
	dot->x1 = ((dot->b * (-1)) - sqrt(dot->discr)) / (2 * dot->a);
	dot->x2 = ((dot->b * (-1)) + sqrt(dot->discr)) / (2 * dot->a);
	find_hit_distance(obj, *dot);
	if (dot->x1 < __FLT_EPSILON__ && dot->x2 < __FLT_EPSILON__)
		return (0);
	return (1);
}

double	cylinder_intersection(t_vector pos, t_vector ray, t_figure **obj)
{
	t_equition	dot;

	if (!solve_cylinder(pos, ray, obj, &dot))
		return (0);
	(*obj)->point.hit_pos = vector_sum(pos, vector_prod(ray, \
		(*obj)->point.dist));
	return ((*obj)->point.dist);
}

// static double	calculate_norm(t_figure **obj, 
// 	t_equition dot)
// {
// 	if (dot.m1 >= 0 && dot.m1 <= (*obj)->cyl->height 
// 		&& dot.x1 < __FLT_EPSILON__ && dot.m2 >= 0 
// 		&& dot.m2 <= (*obj)->cyl->height 
// 		&& dot.x2 < __FLT_EPSILON__)
// 	{
// 		if (dot.x1 > dot.x2)
// 		{
// 			(*obj)->point.dist = dot.m1;
// 			return (dot.x1);
// 		}
// 		else
// 		{
// 			(*obj)->point.dist = dot.m2;
// 			return (dot.x2);
// 		}
// 	}
// 	else if (dot.m1 >= 0 
// 		&& dot.m1 <= (*obj)->cyl->height 
// 		&& dot.x1 < __FLT_EPSILON__)
// 	{
// 		(*obj)->point.dist = dot.m1;
// 		return (dot.x1);
// 	}
// 	(*obj)->point.dist = dot.m2;
// 	return (dot.x2);
// }

// static void	calculate_intersection(t_vector pos, t_vector ray, 
// 	t_figure **obj)
// {
// 	double		x;
// 	t_vector	vec;
// 	t_equition	dot;

// 	if (!check_cyl_intersect(pos, ray, &dot, obj))
// 		return ;
// 	dot.m1 = vector_scalar_prod((*obj)->cyl->axis, 
// 		vector_sub(vector_prod(ray, dot.x1), 
// 		vector_sub((*obj)->cyl->center, pos)));
// 	dot.m2 = vector_scalar_prod((*obj)->cyl->axis, 
// 		vector_sub(vector_prod(ray, dot.x2), 
// 		vector_sub((*obj)->cyl->center, pos)));
// 	x = calculate_norm(obj, dot);
// 	vec = vector_sub(pos, (*obj)->cyl->center);
// 	(*obj)->point.hit_pos = vector_sub(vector_prod(ray, x), 
// 		vector_prod((*obj)->cyl->axis, (*obj)->point.dist));
// 	(*obj)->point.hit_norm = vector_sub((*obj)->point.hit_pos, vec);
// 	normalize_vector(&(*obj)->point.hit_norm);
// }

// double	cylinder_intersection(t_vector pos, t_vector ray, t_figure **obj)
// {
// 	(*obj)->point.dist = 0;
// 	calculate_intersection(pos, ray, obj);
// 	return ((*obj)->point.dist);
// }
