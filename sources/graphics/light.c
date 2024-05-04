/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:57:22 by mnazarya          #+#    #+#             */
/*   Updated: 2024/05/03 16:36:14 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	in_shadow(t_scene *scene, t_vector ray, t_light	*light, t_figure **obj)
{
	double		min;
	double		dist;
	t_figure	*tmp;

	min = INFINITY;
	tmp = scene->figure;
	normalize_vector(&ray);
	while (tmp)
	{
		if (tmp->type == LIGHT)
		{
			tmp = tmp->next;
			continue ;
		}
		if (tmp->type == SPHERE)
			dist = sphere_intersection(light->coordinate, ray, &tmp);
		else if (tmp->type == CYLINDER)
			dist = cylinder_intersection(light->coordinate, ray, &tmp);
		if (dist > __FLT_EPSILON__ && dist < min)
		{
			min = dist;
			*obj = tmp;
		}
		tmp = tmp->next;
	}
	if (min != INFINITY)
		return (0);
	return (1);
}

int	compute_shadow(t_scene *scene, t_vector ray, t_figure **obj, t_light *light)
{
	t_figure	*tmp;

	tmp = NULL;
	(*obj)->point.hit_pos = vector_sum(scene->cam->pos, vector_prod(ray, \
		(*obj)->point.dist));
	if ((*obj)->type == SPHERE)
		(*obj)->point.hit_norm = vector_sub((*obj)->point.hit_pos, \
			(*obj)->sph->center);
	normalize_vector(&(*obj)->point.hit_norm);
	if (!in_shadow(scene, vector_sub((*obj)->point.hit_pos, \
		light->coordinate), light, &tmp) && tmp == *obj)
		return (1);
	return (0);
}

t_color	diffuse_light(t_light *light, t_intersect point)
{
	double		intens;
	double		dot_l;
	t_vector	l;

	intens = 0;
	l = vector_sub(light->coordinate, point.hit_pos);
	normalize_vector(&l);
	dot_l = vector_scalar_prod(point.hit_norm, l);
	if (dot_l > 0)
		intens = light->brightness * dot_l;
	return (calc_rgb_light(light->color, intens));
}

// t_color	specular_light(t_light *light, t_point *point)
// {
// }

		// else if (tmp->type == PLANE)
		// 	dist = plane_intersection(scene, ray, &tmp)
		// else if (tmp->type == CONE)
		// 	dist = cone_intersection(scene, ray, &tmp)