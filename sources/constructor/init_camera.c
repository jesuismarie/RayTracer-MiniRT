/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:42:12 by mnazarya          #+#    #+#             */
/*   Updated: 2024/04/02 14:44:11 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_camera	*new_camera(t_vector pos, t_vector norm, int fov)
{
	t_camera	*cam;

	cam = ft_calloc(1, sizeof(t_camera));
	error_exit(!cam, MALLOC_ERR);
	cam->pos = pos;
	cam->norm = norm;
	cam->fov = fov;
	return (cam);
}
