/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:30:36 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/12 16:08:21 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	event_thread(t_scene *scene, char idx)
{
	if (idx == 'c')
	{
		if (pthread_create(&scene->checker_tid, NULL, \
			(void *(*)(void *))checkerboard_thread, scene) != 0)
			error_exit(1, "Failed to create ray tracing thread");
		pthread_join(scene->checker_tid, NULL);
	}
	if (idx == 'b')
	{
		if (pthread_create(&scene->bump_tid, NULL, \
			(void *(*)(void *))bump_map_thread, scene) != 0)
			error_exit(1, "Failed to create ray tracing thread");
		pthread_join(scene->bump_tid, NULL);
	}
	if (idx == 't')
	{
		if (pthread_create(&scene->texture_tid, NULL, \
			(void *(*)(void *))texture_thread, scene) != 0)
			error_exit(1, "Failed to create ray tracing thread");
		pthread_join(scene->texture_tid, NULL);
	}
	mlx_put_image_to_window(scene->mlx->mlx, scene->mlx->mlx_win, \
		scene->mlx->data.img, 0, 0);
}

void	*checkerboard_thread(t_scene *scene)
{
	pthread_mutex_lock(&scene->checker_mutex);
	clear_window(scene);
	init_scene(scene);
	trace_ray(scene);
	pthread_mutex_unlock(&scene->checker_mutex);
	return (NULL);
}

void	*bump_map_thread(t_scene *scene)
{
	pthread_mutex_lock(&scene->bump_mutex);
	clear_window(scene);
	init_scene(scene);
	trace_ray(scene);
	pthread_mutex_unlock(&scene->bump_mutex);
	return (NULL);
}

void	*texture_thread(t_scene *scene)
{
	pthread_mutex_lock(&scene->texture_mutex);
	clear_window(scene);
	init_scene(scene);
	trace_ray(scene);
	pthread_mutex_unlock(&scene->texture_mutex);
	return (NULL);
}
