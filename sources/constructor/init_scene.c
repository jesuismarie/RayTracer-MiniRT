/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:33:17 by mnazarya          #+#    #+#             */
/*   Updated: 2024/04/04 18:45:10 by mnazarya         ###   ########.fr       */
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
	view_plane->height = view_plane->width / ratio;
	view_plane->x_pixel = view_plane->width / scene->width;
	view_plane->y_pixel = view_plane->height / scene->height;
	return (view_plane);
}

void	init_scene(t_scene **scene)
{
	t_color		col;
	t_color		col1;

	// -------------- replace !!!!!!!!!
	col.r = 0;
	col.g = 255;
	col.b = 255;
	col1.r = 255;
	col1.g = 255;
	col1.b = 255;
	(*scene)->cam = new_camera(new_vector(0, 0, 0), new_vector(0, 0, 1), 70);
	(*scene)->amb = new_amb_light(col, 0.5);
	(*scene)->light = new_light(new_vector(0, 20, 0), col1, 1);
	(*scene)->figure = ft_calloc(1, sizeof(t_figure));
	(*scene)->figure->spec = 0.8;
	(*scene)->figure ->color = col;
	// -------------- Sphere --------------
	(*scene)->figure->type = SPHERE;
	(*scene)->figure->sph = new_sphere(new_vector(0, 0, -32), 4);
	// -------------- Plane ---------------
	//--------------- Cylinder ------------
	// (*scene)->figure->type = CYLINDER;
	// (*scene)->figure->cyl = new_cylinder(new_vector(3, 2, -32), \
	// 	new_vector(0.0,0.0,1.0), 5, 7);
	// -------------- Cone ----------------
	// -------------- replace !!!!!!!!!
	(*scene)->width = WIDTH;
	(*scene)->height = HEIGHT;
	(*scene)->view = get_view_plane(*scene);
}
