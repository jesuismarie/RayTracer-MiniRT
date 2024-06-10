/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_traceing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:53:56 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/07 12:18:02 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vector	look_at(t_scene	*scene, double ray_x, double ray_y)
{
	t_vector	up;
	t_vector	new;
	t_vector	right;
	t_vector	ray_dir;

	up = new_vector(0, 1, 0);
	if (fabs(vector_scalar_prod(scene->cam->norm, up)) > 0.999)
		up = new_vector(0, 0, 1);
	right = vector_cross(scene->cam->norm, up);
	normalize_vector(&right);
	new = vector_cross(right, scene->cam->norm);
	normalize_vector(&new);
	ray_dir = vector_sum(vector_sum(vector_prod(right, ray_x), \
		vector_prod(new, ray_y)), scene->cam->norm);
	normalize_vector(&ray_dir);
	return (ray_dir);
}

void	trace_ray(t_scene *scene)
{
	int			color;
	double		ray_x;
	double		ray_y;
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
			ray = look_at(scene, ray_x, ray_y);
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
