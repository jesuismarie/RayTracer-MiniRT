/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <mnazarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:33:17 by mnazarya          #+#    #+#             */
/*   Updated: 2026/07/18 19:32:10 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vplane	get_view_plane(t_scene *scene)
{
	double		ratio;
	t_vplane	view_plane;

	ratio = WIDTH / scene->height;
	view_plane.mlx_x = 0;
	view_plane.mlx_y = 0;
	view_plane.width = 2 * tan(scene->cam->fov / 2.0 * (M_PI / 180));
	view_plane.height = view_plane.width / ratio;
	view_plane.x_pixel = view_plane.width / WIDTH;
	view_plane.y_pixel = view_plane.height / scene->height;
	return (view_plane);
}

void	load_sphere_textures(t_scene *scene)
{
	t_figure	*fig;

	fig = scene->figure;
	while (fig)
	{
		if (fig->type == SPHERE && fig->sph)
		{
			if (fig->sph->texture_path && !fig->sph->texture_img.img)
				fig->sph->texture_img = load_xpm_image(scene, \
					fig->sph->texture_path);
			if (fig->sph->bump_path && !fig->sph->bump_img.img)
				fig->sph->bump_img = load_xpm_image(scene, \
					fig->sph->bump_path);
		}
		fig = fig->next;
	}
}

void	init_scene(t_scene *scene)
{
	load_sphere_textures(scene);
	scene->width = WIDTH;
	scene->height = HEIGHT;
	scene->view = get_view_plane(scene);
}
