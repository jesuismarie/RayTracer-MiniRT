/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:02:31 by mnazarya          #+#    #+#             */
/*   Updated: 2024/04/02 16:00:44 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	object_intersection(t_scene *scene, t_vector ray, int *color)
{
	float		res;
	t_figure	*tmp;

	tmp = scene->figure;
	while (tmp)
	{
		if (tmp->type == SPHERE)
			res = sphere_intersection(scene, ray, &tmp);
		else if (tmp->type == CYLINDER)
			res = cylinder_intersection(scene, ray, &tmp);
		// else if (tmp->type == PLANE)
		// else if (tmp->type == CONE)
		if (res)
			*color = rgb_to_hex(tmp);
		else
			*color = 0;
		tmp = tmp->next;
	}
}
