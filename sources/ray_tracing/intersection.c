/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:02:31 by mnazarya          #+#    #+#             */
/*   Updated: 2024/03/27 21:16:35 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	object_intersection(t_scene *scene, t_vector ray, int *color)
{
	float		result;
	t_figure	*tmp;

	(void) ray;
	result = 0;
	tmp = scene->figure;
	while (tmp)
	{
		// if (tmp->type == PLANE)
		if (tmp->type == SPHERE)
			result = sphere_intersection(scene, ray, tmp->sph);
		// else if (tmp->type == CYLINDER)
		// else if (tmp->type == CONE)
		if (result)
			*color = rgb_to_hex(tmp);
		else
			*color = 0;
		tmp = tmp->next;
	}
}
