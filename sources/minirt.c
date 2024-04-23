/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:42:40 by mnazarya          #+#    #+#             */
/*   Updated: 2024/04/20 14:46:33 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	main(int argc, char **argv)
{
	t_scene	*scene;

	(void) argc;
	// error_exit(argc != 2, "Wrong count of arguments");
	win_init(&scene);
	img_init(argv, scene);
	mlx_hook(scene->mlx->mlx_win, 2, 1l, &keys, scene);
	mlx_hook(scene->mlx->mlx_win, 17, 1l << 15, &close_win, scene);
	mlx_loop(scene->mlx->mlx);
	return (0);
}
