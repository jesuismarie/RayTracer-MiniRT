/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:23:20 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/11 19:58:09 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_light	ft_parse_light(t_list_token *list)
{
	t_light	light;
	t_token	*tmp;

	tmp = list->head;
	light.coordinate = ft_parse_pos(tmp);
	tmp = ft_jump(tmp, 6);
	light.brightness = ft_atof(tmp->token);
	light.color = ft_parse_color(tmp);
	return (light);
}

bool	ft_create_light(t_scene *scene, t_list_token *list, char **error)
{
	t_light		light;
	t_sphere	*sphere;

	light = ft_parse_light(list);
	if (!ft_validate_color(light.color, error))
		return (set_error(error, ft_format_error(__func__, "")));
	scene->light = ft_light_push_back(scene->light, \
		new_light(light.coordinate, light.color, light.brightness));
	sphere = new_sphere(light.coordinate, light.brightness);
	sphere->color_p = light.color;
	scene->figure = ft_push_back_obj(scene->figure, \
		new_figure(sphere, LIGHT));
	return (true);
}

bool	ft_validate_light_util(t_token **tmp, char **error)
{
	t_token	*prev;

	*tmp = ft_jump(*tmp, 1);
	if (!ft_validate_vector(*tmp, error))
		return (set_error(error, ft_format_error(__func__, "")));
	prev = *tmp;
	*tmp = ft_jump(*tmp, 5);
	if (!ft_validate_color_args(prev, *tmp, error))
		return (set_error(error, ft_format_error(__func__, "")));
	if (*tmp && (*tmp)->next && (*tmp)->next->type == P_SEMI)
		return (set_error(error, ft_format_error(__func__, "")));
	return (true);
}

bool	ft_validate_light(t_list_token *list, char **error)
{
	t_token	*tmp;
	double	ratio;

	tmp = list->head;
	if (!list->head || !list->head->next || \
		list->head->next->type == P_SEMI || \
		list->head->type != P_LIGHT || \
	!ft_pars_args(list, error, LIGHT_MAX_ARGS, LIGHT_MAX_ARGS) \
		|| !ft_pars_semi(list, error, LIGHT_MAX_COLONS))
		return (set_error(error, ft_format_error(__func__, "")));
	tmp = ft_jump(tmp, 1);
	if (!ft_validate_vector(tmp, error))
		return (set_error(error, ft_format_error(__func__, "")));
	tmp = ft_jump(tmp->next, 4);
	if (tmp && tmp->next && tmp->next->type == P_SEMI)
		return (set_error(error, ft_format_error(__func__, "")));
	ratio = ft_atof(tmp->token);
	if (!ft_is_within_range(ratio, 0.0, 1.0))
		return (set_error(error, ft_format_error(__func__, "")));
	if (!ft_validate_light_util(&tmp, error))
		return (set_error(error, ft_format_error(__func__, "")));
	return (true);
}
