/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:44:49 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/12 21:42:52 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	clean_figures(t_scene *scene)
{
	t_figure	*obj_tmp;

	while (scene->figure)
	{
		obj_tmp = scene->figure->next;
		if (scene->figure->type == SPHERE)
			free(scene->figure->sph);
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
