/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:47:04 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/10 00:37:00 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool ft_validate_cylinder_args(t_cylinder cylinder, char **error)
{
    if (!ft_validate_dir(cylinder.axis, error))
        return (set_error(error, ft_format_error(__func__, "")));
    if (!ft_validate_color(cylinder.color_p, error))
        return (set_error(error, ft_format_error(__func__, "")));
	return (true);
}


bool ft_parse_cy_optional_arg(t_cylinder *cylinder, t_list_token *list, t_token **start, char **error)
{
    int count = ft_args_count(list, error);
    if (count == -1)
        return (set_error(error, ft_format_error(__func__, "")));
    if (count == CYLINDER_MAX_ARGS + 1)
	{
		*start = ft_jump(*start, 1);
		cylinder->spec_p = ft_atof((*start)->token);
		if (ft_is_near_equal(cylinder->spec_p, 0) || cylinder->spec_p < 0)
			return (set_error(error, ft_format_error(__func__, "")));
	}
    return (true);
}



bool ft_parse_cylinder(t_list_token *list, t_cylinder *cylinder, char **error)
{
	t_token		*tmp;

	tmp = ft_jump(list->head, 1);
	cylinder->center = ft_parse_pos(tmp);
    tmp = ft_jump(tmp, 5);
    if (!ft_parse_dir(tmp, &cylinder->axis, error))
		return (set_error(error, ft_format_error(__func__, "")));
	tmp = ft_jump(tmp, 5);
    cylinder->radius = ft_atof(tmp->token);
    if (cylinder->radius < 0)
		return (set_error(error, ft_format_error(__func__, "")));
    cylinder->radius /= 2;
    tmp = ft_jump(tmp, 1);
    cylinder->height = ft_atof(tmp->token);
    if (cylinder->height < 0)
		return (set_error(error, ft_format_error(__func__, "")));
	if (!ft_parse_cy_optional_arg(cylinder, list, &tmp, error))
		return (set_error(error, ft_format_error(__func__, "")));
	cylinder->color_p = ft_parse_color(tmp);
	return (true);
}

bool ft_create_cylinder(t_scene *scene, t_list_token	*list, char **error)
{
	t_cylinder *cylinder;

	cylinder = ft_calloc(1, sizeof(t_cylinder));
	if(!ft_parse_cylinder(list, cylinder, error))
		return (set_error(error, ft_format_error(__func__, "")));
	if (!ft_validate_cylinder_args(*cylinder, error))
        return (set_error(error, ft_format_error(__func__, "")));
	scene->figure = ft_push_back_obj(scene->figure, new_figure(cylinder, CYLINDER));
    return (true);
}
