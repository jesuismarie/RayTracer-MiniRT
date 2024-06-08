/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:47:04 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/08 19:03:44 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool ft_validate_dir(t_vector dir, char **error)
{
	double len; 
	
	len = vector_len(dir);
	if (ft_is_near_equal(len, 0)) 
        return (set_error(error, ft_format_error(__func__, "")));
	return (true);
}

bool ft_validate_fov(int fov, char **error)
{
	if (!ft_is_in_range_int(fov, 0, 180))
        return (set_error(error, ft_format_error(__func__, "")));
	return (true);
}

bool ft_validate_camera_args(t_camera camera, char **error)
{
	if (!ft_validate_dir(camera.norm, error))
        return (set_error(error, ft_format_error(__func__, "")));
	if (!ft_validate_fov(camera.fov, error))
        return (set_error(error, ft_format_error(__func__, "")));
	return (true);
}


bool ft_parse_dir(t_token *start, t_vector *dir, char **error)
{
	t_token		*tmp;

	tmp = start;
	dir->x = ft_atof(tmp->token);
	tmp = ft_jump(tmp, 2);
	dir->y = ft_atof(tmp->token);
	tmp = ft_jump(tmp, 2);
	dir->z = ft_atof(tmp->token);
    normalize_vector(dir);
	if (isnan(dir->x) || isnan(dir->y) || isnan(dir->z))
		return (set_error(error, ft_format_error(__func__, "")));
	return (true);
}


t_vector ft_parse_pos(t_token *start)
{
	t_token		*tmp;
	t_vector 	pos;

	tmp = ft_jump(start, 1);
	pos.x = ft_atof(tmp->token);
	tmp = ft_jump(tmp, 2);
	pos.y = ft_atof(tmp->token);
	tmp = ft_jump(tmp, 2);
	pos.z = ft_atof(tmp->token);
	return (pos);
}

t_color ft_parse_color(t_token *start)
{
	t_token		*tmp;
	t_color 	color;

	tmp = ft_jump(start, 1);
	color.r = ft_atoi(tmp->token);
	tmp = ft_jump(tmp, 2);
	color.g = ft_atoi(tmp->token);
	tmp = ft_jump(tmp, 2);
	color.b = ft_atoi(tmp->token);
	return (color);
}


bool ft_parse_camera(t_list_token *list, t_camera *camera, char **error)
{
	t_token		*tmp;

	tmp = ft_jump(list->head, 1);
	camera->pos = ft_parse_pos(tmp);
	tmp = ft_jump(tmp, 5);
	if (!ft_parse_dir(tmp, &camera->norm, error))
		return (set_error(error, ft_format_error(__func__, "")));
	tmp = ft_jump(tmp, 5);
	camera->fov = ft_atoi(tmp->token);
	return (true);
}

bool ft_create_camera(t_scene *scene, t_list_token	*list, char **error)
{
	t_camera	camera;

	if(!ft_parse_camera(list, &camera, error))
		return (set_error(error, ft_format_error(__func__, "")));
	if (!ft_validate_camera_args(camera, error))
        return (set_error(error, ft_format_error(__func__, "")));
	scene->cam = new_camera(camera.pos, camera.norm, camera.fov);
    return (true);
}
