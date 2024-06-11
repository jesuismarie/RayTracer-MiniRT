/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:33:17 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/11 21:14:21 by gehovhan         ###   ########.fr       */
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
	scene->texture = get_pattern(scene, "./resources/textures/texture.xpm", 0);
	scene->bump = get_pattern(scene, "./resources/textures/bump.xpm", 1);
	scene->width = WIDTH;
	scene->height = HEIGHT;
	scene->view = get_view_plane(scene);
}
