/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 21:15:04 by mnazarya          #+#    #+#             */
/*   Updated: 2024/03/27 20:39:39 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	win_init(char **argv, t_scene **scene)
{
	*scene = ft_calloc(1, sizeof(t_scene));
	error_exit(!scene, MALLOC_ERR);
	(*scene)->mlx = ft_calloc(1, sizeof(t_mlx));
	error_exit(!(*scene)->mlx, MALLOC_ERR);
	(*scene)->mlx->mlx = mlx_init();
	(*scene)->mlx->mlx_win = mlx_new_window((*scene)->mlx->mlx, WIDTH, HEIGHT, \
		argv[1]);
}

void	img_init(t_scene *scene)
{
	if (scene->mlx->data.img)
		mlx_destroy_image(scene->mlx, scene->mlx->data.img);
	init_scene(&scene);
	scene->mlx->data.img = mlx_new_image(scene->mlx->mlx, WIDTH, HEIGHT);
	scene->mlx->data.addr = mlx_get_data_addr(scene->mlx->data.img, \
		&scene->mlx->data.bpp, &scene->mlx->data.l, &scene->mlx->data.end);
	trace_ray(scene);
	mlx_put_image_to_window(scene->mlx->mlx, scene->mlx->mlx_win, \
		scene->mlx->data.img, 0, 0);
}
