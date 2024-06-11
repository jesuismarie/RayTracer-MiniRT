/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:42:40 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/11 21:28:35 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_scene	*ft_init_scene(void)
{
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->light = NULL;
	scene->figure = NULL;
	scene->cam = NULL;
	scene->amb = NULL;
	scene->mlx = NULL;
	scene->view = NULL;
	scene->height = 0;
	scene->width = 0;
	return (scene);
}

int	main(int argc, char **argv)
{
	char	*error;
	t_scene	scene;

	(void)argc;
	error_exit(argc != 2, "Wrong count of arguments");
	error = ft_parse(&scene, argv);
	error_exit(error != NULL, error);
	win_init(&scene);
	img_init(&scene);
	mlx_hook(scene.mlx->mlx_win, 2, 1l, &keys, &scene);
	mlx_hook(scene.mlx->mlx_win, 17, 1l << 15, &close_win, &scene);
	mlx_loop(scene.mlx->mlx);
	return (0);
}
