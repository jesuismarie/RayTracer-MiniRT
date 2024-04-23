/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:02:31 by mnazarya          #+#    #+#             */
/*   Updated: 2024/04/22 20:32:39 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	object_intersection(t_scene *scene, t_vector ray, int *color)
{
	float		min;
	float		dist;
	t_figure	*tmp;
	t_figure	*obj;

	obj = NULL;
	min = INFINITY;
	tmp = scene->figure;
	while (tmp)
	{
		if (tmp->type == SPHERE || tmp->type == LIGHT)
			dist = sphere_intersection(scene, ray, &tmp);
		// else if (tmp->type == CYLINDER)
		// 	dist = cylinder_intersection(scene, ray, &tmp);
		// else if (tmp->type == PLANE)
		// else if (tmp->type == CONE)
		if (dist > 0.01 && dist < min)
		{
			min = dist;
			obj = tmp;
		}
		tmp = tmp->next;
	}
	update_pixel_color(scene, obj, color);
}
