/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <mnazarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:44:49 by mnazarya          #+#    #+#             */
/*   Updated: 2026/05/13 17:43:58 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	free_sphere(t_scene *scene, t_sphere *sph)
{
	if (sph->texture_path)
		free(sph->texture_path);
	if (sph->bump_path)
		free(sph->bump_path);
	if (sph->texture_img.img && scene->mlx && scene->mlx->mlx)
		mlx_destroy_image(scene->mlx->mlx, sph->texture_img.img);
	if (sph->bump_img.img && scene->mlx && scene->mlx->mlx)
		mlx_destroy_image(scene->mlx->mlx, sph->bump_img.img);
	free(sph);
}

void	clean_figures(t_scene *scene)
{
	t_figure	*obj_tmp;

	while (scene->figure)
	{
		obj_tmp = scene->figure->next;
		if (scene->figure->type == SPHERE)
			free_sphere(scene, scene->figure->sph);
		else if (scene->figure->type == PLANE)
			free(scene->figure->pln);
		else if (scene->figure->type == CYLINDER)
			free(scene->figure->cyl);
		else if (scene->figure->type == CONE)
			free(scene->figure->cone);
		else if (scene->figure->type == LIGHT)
			free(scene->figure->sph);
		free(scene->figure);
		scene->figure = obj_tmp;
	}
}

void	clear_scene(t_scene *scene)
{
	t_light	*tmp;

	pthread_mutex_destroy(&scene->checker_mutex);
	pthread_mutex_destroy(&scene->bump_mutex);
	pthread_mutex_destroy(&scene->texture_mutex);
	free(scene->amb);
	while (scene->light)
	{
		tmp = scene->light->next;
		free(scene->light);
		scene->light = tmp;
	}
	free(scene->cam);
	clean_figures(scene);
	free(scene->mlx);
}
