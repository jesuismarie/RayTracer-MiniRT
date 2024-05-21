/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:57:22 by mnazarya          #+#    #+#             */
/*   Updated: 2024/05/21 13:16:45 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	in_shadow(t_scene *scene, t_vector ray, t_light	*light, \
	t_figure **obj)
{
	double		min;
	double		dist;
	t_figure	*tmp;

	min = INFINITY;
	tmp = scene->figure;
	while (tmp)
	{
		if (tmp->type == LIGHT)
		{
			tmp = tmp->next;
			continue ;
		}
		dist = check_intersection(light->coordinate, ray, &tmp, 0);
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
	t_vector	light_ray;

	tmp = NULL;
	(*obj)->point.hit_pos = vector_sum(scene->cam->pos, vector_prod(ray, \
		(*obj)->point.dist));
	set_hit_normal(obj, ray);
	light_ray = vector_sub((*obj)->point.hit_pos, light->coordinate);
	normalize_vector(&light_ray);
	if (!in_shadow(scene, light_ray, light, &tmp) && tmp == *obj)
		return (1);
	return (0);
}

t_color	compute_light(t_scene *scene, t_vector ray, t_figure *obj, \
	t_color *spec)
{
	t_color	col;
	t_light	*tmp;

	col = calc_rgb_light(scene->amb->light, scene->amb->ratio);
	tmp = scene->light;
	while (tmp)
	{
		if (compute_shadow(scene, ray, &obj, tmp))
		{
			col = add_rgb_light(diffuse_light(tmp, obj->point), col);
			*spec = specular_light(scene, tmp, obj);
		}
		tmp = tmp->next;
	}
	return (col);
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

t_color	specular_light(t_scene *scene, t_light *light, t_figure *obj)
{
	double		spec;
	t_vector	l;
	t_vector	vec;
	t_vector	reflected;

	spec = 0;
	l = vector_sub(light->coordinate, obj->point.hit_pos);
	normalize_vector(&l);
	vec = vector_sub(scene->cam->pos, obj->point.hit_pos);
	normalize_vector(&vec);
	reflected = reflect_ray(l, obj->point.hit_norm);
	normalize_vector(&reflected);
	if (vector_scalar_prod(reflected, vec) > 0)
		spec = light->brightness * pow(vector_scalar_prod(reflected, vec), \
			obj->spec);
	return (calc_rgb_light(light->color, spec));
}
