/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:42:40 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/11 23:29:40 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	main(int argc, char **argv)
{
	char	*error;
	t_scene	scene;

	ft_bzero(&scene, sizeof(scene));
	error_exit(argc != 2, "Wrong count of arguments");
	error = ft_parse(&scene, argv);
	error_exit(error != NULL, error);
	win_init(&scene);
	img_init(&scene);
	mlx_hook(scene.mlx->mlx_win, 2, 1l << 0, &key_press, &scene);
	mlx_hook(scene.mlx->mlx_win, 17, 1l << 15, &close_win, &scene);
	mlx_loop(scene.mlx->mlx);
	return (0);
}
