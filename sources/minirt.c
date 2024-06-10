/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:42:40 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/11 00:31:50 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

/* TO DO

new vector - sources->vector_functions.c
new_color - sources->graphics->color.c

constructor -> to init all figures, lights and cameras

scene example with all options - > scenes->all.rt
*/

// struct s_scene
// {
// 	t_light		*light;
// 	t_figure	*figure;
// 	t_camera	*cam;
// 	t_amb_light	*amb;
// 	t_mlx		*mlx; // don't touch
// 	t_vplane	*view;
// 	double		height;
// 	double		width;
// };

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
	// scene = ft_init_scene();
	// init_scene(&scene);
	error_exit(argc != 2, "Wrong count of arguments");
	error = ft_parse(&scene, argv);
	ft_printf("%d\n", scene.amb == 0);
	error_exit(error != NULL, error);
	win_init(&scene);
	// init_scene(&scene);
	img_init(&scene);
	mlx_hook(scene.mlx->mlx_win, 2, 1l, &keys, &scene);
	mlx_hook(scene.mlx->mlx_win, 17, 1l << 15, &close_win, &scene);
	mlx_loop(scene.mlx->mlx);
	return (0);
}
