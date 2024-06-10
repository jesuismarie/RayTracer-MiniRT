/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_comera_helper.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:26:16 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/10 15:29:52 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool	ft_parse_dir(t_token *start, t_vector *dir, char **error)
{
	t_token		*tmp;

	tmp = start;
	dir->x = ft_atof(tmp->token);
	tmp = ft_jump(tmp, 2);
	dir->y = ft_atof(tmp->token);
	tmp = ft_jump(tmp, 2);
	dir->z = ft_atof(tmp->token);
	if (!ft_is_within_range(dir->x, -1.0, 1.0) || \
		!ft_is_within_range(dir->y, -1.0, 1.0) || \
		!ft_is_within_range(dir->z, -1.0, 1.0))
		return (set_error(error, ft_format_error(__func__, "")));
	normalize_vector(dir);
	if (isnan(dir->x) || isnan(dir->y) || isnan(dir->z))
		return (set_error(error, ft_format_error(__func__, "")));
	return (true);
}

t_vector	ft_parse_pos(t_token *start)
{
	t_token		*tmp;
	t_vector	pos;

	tmp = ft_jump(start, 1);
	pos.x = ft_atof(tmp->token);
	tmp = ft_jump(tmp, 2);
	pos.y = ft_atof(tmp->token);
	tmp = ft_jump(tmp, 2);
	pos.z = ft_atof(tmp->token);
	return (pos);
}

t_color	ft_parse_color(t_token *start)
{
	t_token	*tmp;
	t_color	color;

	tmp = ft_jump(start, 1);
	color.r = ft_atoi(tmp->token);
	tmp = ft_jump(tmp, 2);
	color.g = ft_atoi(tmp->token);
	tmp = ft_jump(tmp, 2);
	color.b = ft_atoi(tmp->token);
	return (color);
}

bool	ft_parse_camera(t_list_token *list, t_camera *camera, char **error)
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
