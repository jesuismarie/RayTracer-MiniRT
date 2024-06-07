/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:47:04 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/07 22:13:51 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool ft_validate_dir(t_vector dir, char **error)
{
	double len; 
	
	len = vector_len(dir);
	if (ft_is_near_equal(len, 0)) 
	{
		set_error(error, ft_format_error(__func__, ""));
        return (false);
	}
	return (true);
}

bool ft_validate_fov(int fov, char **error)
{
	if (!ft_is_in_range_int(fov, 0, 180))
	{
		set_error(error, ft_format_error(__func__, ""));
        return (false);
	}
	return (true);
}

bool ft_validate_camera_args(t_camera camera, char **error)
{
	if (!ft_validate_dir(camera.norm, error))
	{
		set_error(error, ft_format_error(__func__, ""));
        return (false);
	}
	if (!ft_validate_fov(camera.fov, error))
	{
		set_error(error, ft_format_error(__func__, ""));
        return (false);
	}
	return (true);
}


t_camera ft_parse_camera(t_list_token *list)
{
	t_token		*tmp;
	t_camera 	camera;

	tmp = ft_jump(list->head, 1);
	camera.pos.x = ft_atof(tmp->token);
	tmp = ft_jump(tmp, 2);
	camera.pos.y = ft_atof(tmp->token);
	tmp = ft_jump(tmp, 2);
	camera.pos.z = ft_atof(tmp->token);
	tmp = ft_jump(tmp, 1);
	camera.norm.x = ft_atof(tmp->token);
	tmp = ft_jump(tmp, 2);
	camera.norm.y = ft_atof(tmp->token);
	tmp = ft_jump(tmp, 2);
	camera.norm.z = ft_atof(tmp->token);
	tmp = ft_jump(tmp, 1);
	camera.fov = ft_atoi(tmp->token);
	return (camera);
}

bool ft_create_camera(t_scene *scene, t_list_token	*list, char **error)
{
	t_camera	camera;

	camera = ft_parse_camera(list);
	if (!ft_validate_camera_args(camera, error))
	{
		set_error(error, ft_format_error(__func__, ""));
        return (false);
	}
    // TODO: Normalizing the position of the camera (camera.pos) ?
    normalize_vector(&camera.norm);
	scene->cam = new_camera(camera.pos, camera.norm, camera.fov);
    return (true);
}
