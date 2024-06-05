/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:24:29 by mnazarya          #+#    #+#             */
/*   Updated: 2024/05/24 13:48:03 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_vector	calculate_sph_norm(t_figure *obj)
{
	return (vector_sub(obj->point.hit_pos, obj->sph->center));
}

static t_vector	calculate_pln_norm(t_figure *obj, t_vector ray)
{
	if (vector_scalar_prod(obj->pln->norm, ray) < 0)
		return (obj->pln->norm);
	else
		return (vector_prod(obj->pln->norm, -1));
}

static t_vector	calculate_cyl_norm(t_figure *obj)
{
	double		proj_len;
	t_vector	proj;
	t_vector	vec;

	vec = vector_sub(obj->point.hit_pos, obj->cyl->center);
	proj_len = vector_scalar_prod(vec, obj->cyl->axis);
	proj = vector_sum(obj->cyl->center, vector_prod(obj->cyl->axis, proj_len));
	return (vector_sub(obj->point.hit_pos, proj));
}

static t_vector	calculate_cone_norm(t_figure *obj)
{
	double		proj_len;
	t_vector	vec;

	vec = vector_sub(obj->point.hit_pos, obj->cone->apex);
	proj_len = vector_scalar_prod(vec, obj->cone->axis);
	return (vector_sub(vector_sub(obj->point.hit_pos, \
		obj->cone->apex), vector_prod(obj->cone->axis, proj_len)));
}

void	set_hit_normal(t_figure **obj, t_vector ray)
{
	if ((*obj)->type == SPHERE)
		(*obj)->point.hit_norm = calculate_sph_norm(*obj);
	else if ((*obj)->type == PLANE)
		(*obj)->point.hit_norm = calculate_pln_norm(*obj, ray);
	else if ((*obj)->type == CYLINDER && (*obj)->cyl->cap == 0)
		(*obj)->point.hit_norm = calculate_cyl_norm(*obj);
	else if ((*obj)->type == CYLINDER && (*obj)->cyl->cap == 1)
	{
		if (vector_scalar_prod((*obj)->cyl->axis, ray) < 0)
			(*obj)->point.hit_norm = (*obj)->cyl->axis;
		else
			(*obj)->point.hit_norm = vector_prod((*obj)->cyl->axis, -1);
		(*obj)->cyl->cap = 0;
	}
	else if ((*obj)->type == CONE && (*obj)->cone->cap == 1)
	{
		if (vector_scalar_prod((*obj)->cone->axis, ray) < 0)
			(*obj)->point.hit_norm = (*obj)->cone->axis;
		else
			(*obj)->point.hit_norm = vector_prod((*obj)->cone->axis, -1);
		(*obj)->cone->cap = 0;
	}
	else if ((*obj)->type == CONE && (*obj)->cone->cap == 0)
		(*obj)->point.hit_norm = calculate_cone_norm(*obj);
	normalize_vector(&(*obj)->point.hit_norm);
}
