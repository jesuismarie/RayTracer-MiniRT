/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:33:17 by mnazarya          #+#    #+#             */
/*   Updated: 2024/03/27 20:50:48 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	init_scene(t_scene **scene)
{
	t_color		col;

	//replace
	col.r = 0;
	col.g = 255;
	col.b = 255;
	(*scene)->cam = new_camera(new_vector(0, 0, 0), new_vector(0, 0, -1), 70);
	(*scene)->amb = new_amb_light(col, 0.5);
	(*scene)->figure = ft_calloc(1, sizeof(t_figure));
	(*scene)->figure->sph = new_sphere(new_vector(3, 2, -32), col, 3, -1);
	// !!
	(*scene)->width = WIDTH;
	(*scene)->height = HEIGHT;
}
