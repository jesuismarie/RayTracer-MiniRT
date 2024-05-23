/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:33:17 by mnazarya          #+#    #+#             */
/*   Updated: 2024/05/23 15:59:04 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vplane	*get_view_plane(t_scene *scene)
{
	double		ratio;
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
	t_color		col2;
	t_color		col3;

	// -------------- replace !!!!!!!!!
	col.r = 255;
	col.g = 255;
	col.b = 255;
	col1.r = 0;
	col1.g = 255;
	col1.b = 255;
	col2.r = 0;
	col2.g = 255;
	col2.b = 0;
	col3.r = 255;
	col3.g = 0;
	col3.b = 0;
	(*scene)->cam = new_camera(new_vector(0, 0, 0), new_vector(0, 0, -1), 70);
	(*scene)->amb = new_amb_light(col, 0.2);
	// -------------- Light --------------
	(*scene)->light = new_light(new_vector(15, 10, -1), col, 0.8);
	(*scene)->figure = ft_calloc(1, sizeof(t_figure));
	(*scene)->figure->type = LIGHT;
	(*scene)->figure->color = col;
	(*scene)->figure->sph = new_sphere(new_vector(15, 10, -1), 0.8);
	// -------------- Sphere 1 --------------
	(*scene)->figure->next = ft_calloc(1, sizeof(t_figure));
	(*scene)->figure->next->spec = 100;
	(*scene)->figure->next->color = col3;
	(*scene)->figure->next->type = SPHERE;
	(*scene)->figure->next->sph = new_sphere(new_vector(2, 0, -30), 3);
	(*scene)->figure->next->sph->checkerboard = 1;
	// -------------- Sphere 2 --------------
	(*scene)->figure->next->next = ft_calloc(1, sizeof(t_figure));
	(*scene)->figure->next->next->spec = 500;
	(*scene)->figure->next->next->color = col2;
	(*scene)->figure->next->next->type = SPHERE;
	(*scene)->figure->next->next->sph = new_sphere(new_vector(7, 0, -25), 1);
	// -------------- Plane ---------------
	(*scene)->figure->next->next->next = ft_calloc(1, sizeof(t_figure));
	(*scene)->figure->next->next->next->spec = 500;
	(*scene)->figure->next->next->next->color = col;
	(*scene)->figure->next->next->next->type = PLANE;
	(*scene)->figure->next->next->next->pln = new_plane(new_vector(0, 0, -42), \
		new_vector(0.4, 0, 0.6));
	//--------------- Cylinder ------------
	(*scene)->figure->next->next->next->next = ft_calloc(1, sizeof(t_figure));
	(*scene)->figure->next->next->next->next->spec = 200;
	(*scene)->figure->next->next->next->next->color = col2;
	(*scene)->figure->next->next->next->next->type = CYLINDER;
	(*scene)->figure->next->next->next->next->cyl = \
		new_cylinder(new_vector(-8, -12, -27), new_vector(0, 1, 0), 3, 10);
	// -------------- Cone ----------------
	(*scene)->figure->next->next->next->next->next = ft_calloc(1, sizeof(t_figure));
	(*scene)->figure->next->next->next->next->next->spec = 200;
	(*scene)->figure->next->next->next->next->next->color = col1;
	(*scene)->figure->next->next->next->next->next->type = CONE;
	(*scene)->figure->next->next->next->next->next->cone = \
		new_cone(new_vector(10, 15, -22), new_vector(0, -1, 0), 3, 10);
	// -------------- replace !!!!!!!!!
	(*scene)->width = WIDTH;
	(*scene)->height = HEIGHT;
	(*scene)->view = get_view_plane(*scene);
}
