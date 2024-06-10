/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:33:17 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/11 01:17:49 by gehovhan         ###   ########.fr       */
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

void	init_scene(t_scene *scene)
{
	t_vector	norm;
	t_color		col;
	t_color		col1;
	t_color		col2;
	t_color		col3;
	t_figure*	figure = NULL;
	scene->texture = get_pattern(scene, "./resources/textures/texture.xpm", 0);
	scene->bump = get_pattern(scene, "./resources/textures/bump.xpm", 1);
	
	// -------------- replace !!!!!!!!!
	col = new_color(255, 255, 255);
	col1 = new_color(0, 255, 255);
	col2 = new_color(0, 255, 0);
	col3 = new_color(255, 0, 0);
	norm = new_vector(0, 1, 0);
	normalize_vector(&norm);
	// scene->cam = new_camera(new_vector(0, 0, 0), new_vector(0, 0, -1), 70);
	// (scene)->amb = new_amb_light(col, 0.2);
	// -------------- Light --------------
	// (scene)->light = new_light(new_vector(20, 5, -10), col, 0.6);
	// (scene)->figure = ft_calloc(1, sizeof(t_figure));
	// (scene)->figure->type = LIGHT;
	// (scene)->figure->color = col;
	// (scene)->figure->sph = new_sphere(new_vector(20, 5, -10), 0.6);
	// -------------- Sphere 1 --------------
	// figure = ft_calloc(1, sizeof(t_figure));
	// figure->spec = 100;
	// figure->color = col3;
	// figure->type = SPHERE;
	// figure->sph = new_sphere(new_vector(2, 1, -30), 2);
	// figure->sph->bump = 1;
	// figure->sph->texture = 1;
	// // -------------- Sphere 2 --------------
	// figure = ft_calloc(1, sizeof(t_figure));
	// figure->spec = 500;
	// figure->color = col2;
	// figure->type = SPHERE;
	// figure->sph = new_sphere(new_vector(7, 0, -30), 1);
	// figure->sph->checkerboard = 1;
	// // -------------- Plane ---------------
	figure = ft_calloc(1, sizeof(t_figure));
	figure->spec = 500;
	figure->color = col;
	figure->type = PLANE;
	figure->pln = new_plane(new_vector(0, -1, 0), \
		new_vector(0, 1, 0));
	// //--------------- Cylinder ------------
	figure->next = ft_calloc(1, sizeof(t_figure));
	figure->next->spec = 200;
	figure->next->color = col3;
	figure->next->type = CYLINDER;
	figure->next->cyl = \
		new_cylinder(new_vector(-8, -1, -20), norm, 2, 5);
	// // -------------- Cone ----------------
	figure->next->next = ft_calloc(1, \
		sizeof(t_figure));
	figure->next->next->spec = 200;
	figure->next->next->color = col1;
	figure->next->next->type = CONE;
	figure->next->next->cone = \
		new_cone(new_vector(9, -1, -17), norm, 2, 5);
	scene->figure = ft_push_back_obj(scene->figure, figure);
	
	// -------------- replace !!!!!!!!!
	scene->width = WIDTH;
	scene->height = HEIGHT;
	scene->view = get_view_plane(scene);
}
