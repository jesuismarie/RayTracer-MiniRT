/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:44:49 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/11 23:35:24 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	clean_figures(t_scene **scene)
{
	t_figure	*obj_tmp;

	while ((*scene)->figure)
	{
		obj_tmp = (*scene)->figure->next;
		if ((*scene)->figure->type == SPHERE)
			free((*scene)->figure->sph);
		else if ((*scene)->figure->type == PLANE)
			free((*scene)->figure->pln);
		else if ((*scene)->figure->type == CYLINDER)
			free((*scene)->figure->cyl);
		else if ((*scene)->figure->type == CONE)
			free((*scene)->figure->cone);
		free((*scene)->figure);
		(*scene)->figure = obj_tmp;
	}
}

void	clear_scene(t_scene **scene)
{
	t_light	*tmp;

	pthread_mutex_destroy(&(*scene)->checker_mutex);
	pthread_mutex_destroy(&(*scene)->bump_mutex);
	pthread_mutex_destroy(&(*scene)->texture_mutex);
	free((*scene)->amb);
	while ((*scene)->light)
	{
		tmp = (*scene)->light->next;
		free((*scene)->light);
		(*scene)->light = tmp;
	}
	free((*scene)->cam);
	clean_figures(scene);
	free((*scene)->mlx);
	free(*scene);
}
