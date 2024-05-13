/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:02:31 by mnazarya          #+#    #+#             */
/*   Updated: 2024/05/13 21:14:38 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	object_intersection(t_scene *scene, t_vector ray, int *color)
{
	double		min;
	double		dist;
	t_figure	*tmp;
	t_figure	*obj;

	obj = NULL;
	min = INFINITY;
	tmp = scene->figure;
	while (tmp)
	{
		if (tmp->type == SPHERE || tmp->type == LIGHT)
			dist = sphere_intersection(scene->cam->pos, ray, &tmp);
		else if (tmp->type == CYLINDER)
			dist = cylinder_intersection(scene->cam->pos, ray, &tmp);
		else if (tmp->type == PLANE)
			dist = plane_intersection(scene->cam->pos, ray, &tmp);
		if (dist > __FLT_EPSILON__ && dist < min)
		{
			min = dist;
			obj = tmp;
		}
		tmp = tmp->next;
	}
	update_pixel_color(scene, obj, color, ray);
}

		// else if (tmp->type == CONE)
		// 	dist = cone_intersection(scene, ray, &tmp)
