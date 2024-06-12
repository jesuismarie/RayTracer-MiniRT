/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 21:15:04 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/13 00:03:11 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	win_init(t_scene *scene)
{
	error_exit(!scene, MALLOC_ERR);
	scene->mlx = ft_calloc(1, sizeof(t_mlx));
	error_exit(!scene->mlx, MALLOC_ERR);
	scene->mlx->mlx = mlx_init();
	error_exit(!scene->mlx->mlx, MALLOC_ERR);
	scene->mlx->mlx_win = mlx_new_window((scene)->mlx->mlx, \
			WIDTH, HEIGHT, "miniRT");
	error_exit(!scene->mlx->mlx_win, MALLOC_ERR);
	pthread_mutex_init(&scene->checker_mutex, NULL);
	pthread_mutex_init(&scene->bump_mutex, NULL);
	pthread_mutex_init(&scene->texture_mutex, NULL);
}

void	img_init(t_scene *scene)
{
	init_scene(scene);
	scene->mlx->data.img = mlx_new_image(scene->mlx->mlx, WIDTH, HEIGHT);
	scene->mlx->data.addr = mlx_get_data_addr(scene->mlx->data.img, \
		&scene->mlx->data.bpp, &scene->mlx->data.l, &scene->mlx->data.end);
	trace_ray(scene);
	mlx_put_image_to_window(scene->mlx->mlx, scene->mlx->mlx_win, \
		scene->mlx->data.img, 0, 0);
}
