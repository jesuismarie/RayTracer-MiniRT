/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:42:40 by mnazarya          #+#    #+#             */
/*   Updated: 2024/02/28 17:34:22 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	main(int argc, char **argv)
{
	t_scene	*scene;

	(void)argv;
	if (argc != 2)
		return (print_err("Wrong count of arguments"));
	scene = ft_calloc(1, sizeof(t_scene));
	scene->mlx = ft_calloc(1, sizeof(t_mlx));
	scene->mlx->mlx = mlx_init();
	scene->mlx->mlx_win = mlx_new_window(scene->mlx->mlx, WIDTH, HEIGHT, \
	argv[1]);
	mlx_hook(scene->mlx->mlx_win, 2, 1l, &keys, scene);
	mlx_hook(scene->mlx->mlx_win, 17, 1l << 15, &close_win, scene);
	mlx_loop(scene->mlx->mlx);
	return (0);
}
