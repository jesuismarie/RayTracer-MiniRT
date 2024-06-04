/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:33:17 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/04 15:34:13 by mnazarya         ###   ########.fr       */
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
	t_vector	norm;
	t_color		col;
	t_color		col1;
	t_color		col2;
	t_color		col3;
	// -------------- replace !!!!!!!!!
	col = new_color(255, 255, 255);
	col1 = new_color(0, 255, 255);
	col2 = new_color(0, 255, 0);
	col3 = new_color(255, 0, 0);
	norm = new_vector(0, -1, 0);
	normalize_vector(&norm);
	(*scene)->texture = get_pattern(*scene, "./resources/textures/texture.xpm");
	(*scene)->bump = get_pattern(*scene, "./resources/textures/bump.xpm");
	(*scene)->cam = new_camera(new_vector(0, 0, 0), new_vector(0, 0, -1), 70);
	(*scene)->amb = new_amb_light(col, 0.2);
	// -------------- Light --------------
	(*scene)->light = new_light(new_vector(20, 5, -10), col, 0.6);
	(*scene)->figure = ft_calloc(1, sizeof(t_figure));
	(*scene)->figure->type = LIGHT;
	(*scene)->figure->color = col;
	(*scene)->figure->sph = new_sphere(new_vector(20, 5, -10), 0.6);
	// -------------- Sphere 1 --------------
	(*scene)->figure->next = ft_calloc(1, sizeof(t_figure));
	(*scene)->figure->next->spec = 100;
	(*scene)->figure->next->color = col3;
	(*scene)->figure->next->type = SPHERE;
	(*scene)->figure->next->sph = new_sphere(new_vector(2, 1, -20), 2);
	(*scene)->figure->next->sph->bump = 1;
	(*scene)->figure->next->sph->texture = 1;
	// -------------- Sphere 2 --------------
	(*scene)->figure->next->next = ft_calloc(1, sizeof(t_figure));
	(*scene)->figure->next->next->spec = 500;
	(*scene)->figure->next->next->color = col2;
	(*scene)->figure->next->next->type = SPHERE;
	(*scene)->figure->next->next->sph = new_sphere(new_vector(7, 0, -25), 1);
	(*scene)->figure->next->next->sph->checkerboard = 1;
	// -------------- Plane ---------------
	(*scene)->figure->next->next->next = ft_calloc(1, sizeof(t_figure));
	(*scene)->figure->next->next->next->spec = 500;
	(*scene)->figure->next->next->next->color = col;
	(*scene)->figure->next->next->next->type = PLANE;
	(*scene)->figure->next->next->next->pln = new_plane(new_vector(0, -1, 0), \
		new_vector(0, 1, 0));
	//--------------- Cylinder ------------
	(*scene)->figure->next->next->next->next = ft_calloc(1, sizeof(t_figure));
	(*scene)->figure->next->next->next->next->spec = 200;
	(*scene)->figure->next->next->next->next->color = col3;
	(*scene)->figure->next->next->next->next->type = CYLINDER;
	(*scene)->figure->next->next->next->next->cyl = \
		new_cylinder(new_vector(-10, 4, -27), norm, 2, 5);
	// -------------- Cone ----------------
	(*scene)->figure->next->next->next->next->next = ft_calloc(1, \
		sizeof(t_figure));
	(*scene)->figure->next->next->next->next->next->spec = 200;
	(*scene)->figure->next->next->next->next->next->color = col1;
	(*scene)->figure->next->next->next->next->next->type = CONE;
	(*scene)->figure->next->next->next->next->next->cone = \
		new_cone(new_vector(8, 4, -20), norm, 2, 5);
	// -------------- replace !!!!!!!!!
	(*scene)->width = WIDTH;
	(*scene)->height = HEIGHT;
	(*scene)->view = get_view_plane(*scene);
}
