/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:47:04 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/11 00:22:57 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool	ft_validate_dir(t_vector dir, char **error)
{
	double	len;

	len = vector_len(dir);
	if (ft_is_near_equal(len, 0))
		return (set_error(error, ft_format_error(__func__, "")));
	return (true);
}

bool	ft_validate_fov(int fov, char **error)
{
	if (!ft_is_in_range_int(fov, 0, 180))
		return (set_error(error, ft_format_error(__func__, "")));
	return (true);
}

bool	ft_validate_camera_args(t_camera camera, char **error)
{
	if (!ft_validate_dir(camera.norm, error))
		return (set_error(error, ft_format_error(__func__, "")));
	if (!ft_validate_fov(camera.fov, error))
		return (set_error(error, ft_format_error(__func__, "")));
	return (true);
}

bool	ft_create_camera(t_scene *scene, t_list_token	*list, char **error)
{
	t_camera	camera;

	if (!ft_parse_camera(list, &camera, error))
		return (set_error(error, ft_format_error(__func__, "")));
	if (!ft_validate_camera_args(camera, error))
		return (set_error(error, ft_format_error(__func__, "")));
	if (scene->cam)
		return (set_error(error, ft_format_error(__func__, "")));
	printf("%lf %lf %lf\n", camera.norm.x, camera.norm.y, camera.norm.z);
	scene->cam = new_camera(camera.pos, camera.norm, camera.fov);
	return (true);
}
