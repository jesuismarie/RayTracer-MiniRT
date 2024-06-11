/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:47:04 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/11 19:57:25 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool	ft_validate_cone_args(t_cone cone, char **error)
{
	if (!ft_validate_dir(cone.axis, error))
		return (set_error(error, ft_format_error(__func__, "")));
	if (!ft_validate_color(cone.color_p, error))
		return (set_error(error, ft_format_error(__func__, "")));
	return (true);
}

bool	ft_parse_co_optional_arg(t_cone *cone, \
	t_list_token *list, t_token **start, char **error)
{
	int	count;

	count = ft_args_count(list, error);
	if (count == -1)
		return (set_error(error, ft_format_error(__func__, "")));
	if (count == CONE_MAX_ARGS + 1)
	{
		*start = ft_jump(*start, 1);
		cone->spec_p = ft_atof((*start)->token);
		if (ft_is_near_equal(cone->spec_p, 0) || cone->spec_p < 0)
			return (set_error(error, ft_format_error(__func__, "")));
	}
	return (true);
}

bool	ft_parse_cone(t_list_token *list, t_cone *cone, char **error)
{
	t_token		*tmp;

	tmp = list->head;
	cone->center = ft_parse_pos(tmp);
	tmp = ft_jump(tmp, 6);
	if (!ft_parse_dir(tmp, &cone->axis, error))
		return (set_error(error, ft_format_error(__func__, "")));
	tmp = ft_jump(tmp, 5);
	cone->radius = ft_atof(tmp->token);
	if (cone->radius < 0)
		return (set_error(error, ft_format_error(__func__, "")));
	cone->radius /= 2;
	tmp = ft_jump(tmp, 1);
	cone->height = ft_atof(tmp->token);
	if (cone->height < 0)
		return (set_error(error, ft_format_error(__func__, "")));
	if (!ft_parse_co_optional_arg(cone, list, &tmp, error))
		return (set_error(error, ft_format_error(__func__, "")));
	cone->color_p = ft_parse_color(tmp);
	return (true);
}

bool	ft_create_cone(t_scene *scene, t_list_token	*list, char **error)
{
	t_cone	cone;
	t_cone	*new_obj;

	if (!ft_parse_cone(list, &cone, error))
		return (set_error(error, ft_format_error(__func__, "")));
	if (!ft_validate_cone_args(cone, error))
		return (set_error(error, ft_format_error(__func__, "")));
	new_obj = new_cone(cone.center, cone.axis, cone.radius, cone.height);
	new_obj->color_p = cone.color_p;
	new_obj->spec_p = cone.spec_p;
	scene->figure = ft_push_back_obj(scene->figure, new_figure(new_obj, CONE));
	return (true);
}
