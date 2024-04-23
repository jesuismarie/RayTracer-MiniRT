/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:57:22 by mnazarya          #+#    #+#             */
/*   Updated: 2024/04/23 16:27:39 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	in_shadow(t_scene *scene, t_vector ray)
{
	float		min;
	float		dist;
	t_figure	*tmp;

	min = INFINITY;
	tmp = scene->figure;
	while (tmp)
	{
		if (tmp->type == SPHERE)
			dist = sphere_intersection(scene, ray, &tmp);
		// else if (tmp->type == CYLINDER)
		// 	dist = cylinder_intersection(scene, ray, &tmp);
		// else if (tmp->type == PLANE)
		// else if (tmp->type == CONE)
		if (dist > 0.01 && dist < min)
			min = dist;
		tmp = tmp->next;
	}
	if (min != INFINITY)
		return (0);
	return (1);
}

t_color	diffuse_light(t_light *light, t_intersect point)
{
	float		intens;
	float		dot_l;
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
