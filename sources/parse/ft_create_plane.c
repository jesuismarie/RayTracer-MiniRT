/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:47:04 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/11 20:05:37 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool	ft_validate_plane_args(t_plane plane, char **error)
{
	if (!ft_validate_dir(plane.norm, error))
		return (set_error(error, ft_format_error(__func__, "")));
	if (!ft_validate_color(plane.color_p, error))
		return (set_error(error, ft_format_error(__func__, "")));
	return (true);
}

bool	ft_parse_optional_arg(t_plane *plane, \
	t_list_token *list, t_token **start, char **error)
{
	int		count;

	count = ft_args_count(list, error);
	if (count == -1)
		return (set_error(error, ft_format_error(__func__, "")));
	if (count == PLANE_MAX_ARGS + 1)
	{
		*start = ft_jump(*start, 1);
		plane->spec_p = ft_atof((*start)->token);
		if (ft_is_near_equal(plane->spec_p, 0) || plane->spec_p < 0)
			return (set_error(error, ft_format_error(__func__, "")));
	}
	return (true);
}

bool	ft_parse_plane(t_list_token *list, \
	t_plane *plane, char **error)
{
	t_token		*tmp;

	tmp = list->head;
	plane->pos = ft_parse_pos(tmp);
	tmp = ft_jump(tmp, 6);
	if (!ft_parse_dir(tmp, &plane->norm, error))
		return (set_error(error, ft_format_error(__func__, "")));
	tmp = ft_jump(tmp, 4);
	if (!ft_parse_optional_arg(plane, list, &tmp, error))
		return (set_error(error, ft_format_error(__func__, "")));
	plane->color_p = ft_parse_color(tmp);
	return (true);
}

bool	ft_create_plane(t_scene *scene, t_list_token	*list, char **error)
{
	t_plane	plane;
	t_plane	*new_obj;

	if (!ft_parse_plane(list, &plane, error))
		return (set_error(error, ft_format_error(__func__, "")));
	if (!ft_validate_plane_args(plane, error))
		return (set_error(error, ft_format_error(__func__, "")));
	new_obj = new_plane(plane.pos, plane.norm);
	new_obj->color_p = plane.color_p;
	new_obj->spec_p = plane.spec_p;
	scene->figure = ft_push_back_obj(scene->figure, new_figure(new_obj, PLANE));
	return (true);
}
