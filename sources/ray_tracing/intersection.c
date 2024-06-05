/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:02:31 by mnazarya          #+#    #+#             */
/*   Updated: 2024/05/21 13:19:43 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	check_intersection(t_vector pos, t_vector ray, t_figure **obj, \
	int light)
{
	if ((*obj)->type == SPHERE)
		return (sphere_intersection(pos, ray, obj));
	else if ((*obj)->type == LIGHT && light)
		return (sphere_intersection(pos, ray, obj));
	else if ((*obj)->type == CYLINDER)
		return (cylinder_intersection(pos, ray, obj));
	else if ((*obj)->type == PLANE)
		return (plane_intersection(pos, ray, obj));
	else if ((*obj)->type == CONE)
		return (cone_intersection(pos, ray, obj));
	return (0);
}

void	object_intersection(t_scene *scene, t_vector ray, int *color)
{
	double		min;
	double		dist;
	t_figure	*tmp;
	t_figure	*obj;

	obj = NULL;
	*color = 0;
	min = INFINITY;
	tmp = scene->figure;
	while (tmp)
	{
		dist = check_intersection(scene->cam->pos, ray, &tmp, 1);
		if (dist > __FLT_EPSILON__ && dist < min)
		{
			min = dist;
			obj = tmp;
		}
		tmp = tmp->next;
	}
	update_pixel_color(scene, ray, obj, color);
}
