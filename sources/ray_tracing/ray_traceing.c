/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_traceing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:53:56 by mnazarya          #+#    #+#             */
/*   Updated: 2024/04/01 19:15:02 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	trace_ray(t_scene *scene)
{
	int			color;
	float		ray_x;
	float		ray_y;
	t_vector	ray;

	scene->view->y_angle = scene->height / 2;
	while (scene->view->y_angle >= (scene->height / 2) * (-1))
	{
		scene->view->mlx_x = 0;
		ray_y = scene->view->y_pixel * scene->view->y_angle;
		scene->view->x_angle = (scene->width / 2) * (-1);
		while (scene->view->x_angle <= scene->width / 2)
		{
			ray_x = scene->view->x_pixel * scene->view->x_angle;
			ray = new_vector(ray_x, ray_y, -1);
			normalize_vector(&ray);
			object_intersection(scene, ray, &color);
			my_mlx_pixel_put(scene, scene->view->mlx_x, \
				scene->view->mlx_y, color);
			scene->view->mlx_x++;
			scene->view->x_angle++;
		}
		scene->view->mlx_y++;
		scene->view->y_angle--;
	}
}
