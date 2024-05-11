/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:42:40 by mnazarya          #+#    #+#             */
/*   Updated: 2024/05/09 14:15:33 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

/* TO DO

new vector - sources->vector_functions.c
new_color - sources->graphics->color.c

constructor -> to init all figures, lights and cameras

scene example with all options - > scenes->all.rt
*/

int	main(int argc, char **argv)
{
	t_scene	*scene;

	(void) argv;
	(void) argc;
	// error_exit(argc != 2, "Wrong count of arguments");
	win_init(&scene);
	img_init(scene);
	mlx_hook(scene->mlx->mlx_win, 2, 1l, &keys, scene);
	mlx_hook(scene->mlx->mlx_win, 17, 1l << 15, &close_win, scene);
	mlx_loop(scene->mlx->mlx);
	return (0);
}
