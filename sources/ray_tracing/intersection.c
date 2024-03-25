/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:02:31 by mnazarya          #+#    #+#             */
/*   Updated: 2024/03/25 21:21:07 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	object_intersection(t_scene *scene, t_vector ray, t_point *point)
{
	t_figure	*tmp;

	tmp = scene->figure;
	while (tmp)
	{
		// if (tmp->type == PLANE)

		// else if (tmp->type == SPHERE)

		// else if (tmp->type == CYLINDER)

		// else if (tmp->type == CONE)
		
		tmp = tmp->next;
	}
}
