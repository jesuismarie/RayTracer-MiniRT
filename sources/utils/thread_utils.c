/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:30:36 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/11 23:31:09 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	*trace_ray_thread(t_scene *scene)
{
	pthread_mutex_lock(&scene->checker_mutex);
	clear_window(scene);
	init_scene(scene);
	trace_ray(scene);
	pthread_mutex_unlock(&scene->checker_mutex);
	return (NULL);
}
