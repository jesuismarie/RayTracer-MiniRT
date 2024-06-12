/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:42:40 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/13 00:01:52 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static char	*ft_check_minimum_requirements(t_scene *scene)
{
	if (!scene->cam)
		return (ft_strdup("Requirement: non existing camera"));
	if (!scene->amb)
		return (ft_strdup("Requirement: non existing ambient light"));
	if (!scene->light)
		return (ft_strdup("Requirement: non existing light"));
	return (NULL);
}

int	main(int argc, char **argv)
{
	char	*error;
	t_scene	scene;

	ft_bzero(&scene, sizeof(t_scene));
	error_exit(argc != 2, "Wrong count of arguments");
	if (!ft_strrchr(argv[1], '.') \
		|| ft_strcmp_std(ft_strrchr(argv[1], '.'), ".rt"))
		error_exit(1, "Wrong file type");
	error = ft_parse(&scene, argv);
	error_exit_allocated(error != NULL, error);
	error = NULL;
	win_init(&scene);
	error = ft_check_minimum_requirements(&scene);
	error_exit_allocated(error != NULL, error);
	img_init(&scene);
	mlx_hook(scene.mlx->mlx_win, 2, 1l << 0, &key_press, &scene);
	mlx_hook(scene.mlx->mlx_win, 17, 1l << 15, &close_win, &scene);
	mlx_loop(scene.mlx->mlx);
	return (0);
}
