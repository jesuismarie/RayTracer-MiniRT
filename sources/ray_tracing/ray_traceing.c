/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_traceing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:53:56 by mnazarya          #+#    #+#             */
/*   Updated: 2024/03/25 20:41:16 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vplane	*get_view_plane(t_scene *scene)
{
	float		ratio;
	t_vplane	*view_plane;

	ratio = scene->width / scene->height;
	view_plane = ft_calloc(1, sizeof(t_vplane));
	error_exit(!view_plane, MALLOC_ERR);
	view_plane->mlx_x = 0;
	view_plane->mlx_y = 0;
	view_plane->width = 2 * tan(scene->cam->fov / 2 * (M_PI / 180));
	view_plane->height = scene->width / ratio;
	view_plane->x_pixel = view_plane->width / scene->width;
	view_plane->x_pixel = view_plane->height / scene->height;
	return (view_plane);
}

void	trace_ray(t_scene *scene)
{
	int			ray_x;
	int			ray_y;
	t_vector	ray;
	t_point		point;
	t_vplane	*view;

	view = get_view_plane(scene);
	view->y_angle = scene->height / 2;
	while (view->y_angle >= (scene->height / 2) * (-1))
	{
		ray_y = view->y_pixel * view->y_angle;
		view->x_angle = (scene->width / 2) * (-1);
		while (view->x_angle <= scene->width / 2)
		{
			ray_x = view->x_pixel * view->x_angle;
			ray = new_vector(ray_x, ray_y, -1);
			normalize_vector(ray);
			object_intersection(scene, ray, &point);
			my_mlx_pixel_put(scene, view->mlx_x, view->mlx_y, point.color);
			view->mlx_x++;
			view->x_angle++;
		}
		view->mlx_y--;
		view->y_angle--;
	}
}
