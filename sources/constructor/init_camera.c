/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:42:12 by mnazarya          #+#    #+#             */
/*   Updated: 2024/03/27 20:35:27 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_camera	*new_camera(t_vector pos, t_vector dir, int fov)
{
	t_camera	*cam;

	cam = ft_calloc(1, sizeof(t_camera));
	error_exit(!cam, MALLOC_ERR);
	cam->position = pos;
	cam->dir = dir;
	cam->fov = fov;
	return (cam);
}
