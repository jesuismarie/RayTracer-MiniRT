/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_amb_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 22:46:32 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/10 23:51:52 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_amb_light	ft_parse_amb(t_list_token *list)
{
	t_token		*tmp;
	t_amb_light	amb_obj;

	tmp = ft_jump(list->head, 1);
	amb_obj.ratio = ft_atof(tmp->token);
	amb_obj.light = ft_parse_color(tmp);
	return (amb_obj);
}

bool	ft_create_amb_light(t_scene *scene, t_list_token *list, char **error)
{
	t_amb_light	amb_obj;

	amb_obj = ft_parse_amb(list);
	if (!ft_validate_color(amb_obj.light, error))
		return (set_error(error, ft_format_error(__func__, "")));
	if (scene->amb)
		return (set_error(error, ft_format_error(__func__, "")));
	scene->amb = new_amb_light(amb_obj.light, amb_obj.ratio);
	return (true);
}

bool	ft_validate_amb_light(t_list_token	*list, char **error)
{

	t_token	*tmp;
	t_token	*prev;
	double	ratio;

	tmp = list->head;
	if (!list->head || !list->head->next || list->head->next->type == P_SEMI \
		|| list->head->type != P_AMB_LIGHT \
		|| !ft_pars_args(list, error, AMB_MAX_ARGS, AMB_MAX_ARGS) \
		|| !ft_pars_semi(list, error, AMB_MAX_COLONS))
		return (set_error(error, ft_format_error(__func__, "")));
	tmp = ft_jump(tmp, 1);
	ratio = ft_atof(tmp->token);
	if (!ft_is_within_range(ratio, 0.0, 1.0))
		return (set_error(error, ft_format_error(__func__, "")));
	tmp = ft_jump(tmp, 1);
	if (!ft_validate_vector(tmp, error))
		return (set_error(error, ft_format_error(__func__, "")));
	prev = tmp;
	tmp = ft_jump(tmp, 5);
	if (!ft_validate_color_args(prev, tmp, error))
		return (set_error(error, ft_format_error(__func__, "")));
	if (tmp && tmp->next && tmp->next->type == P_SEMI)
		return (set_error(error, ft_format_error(__func__, "")));
	return (true);
}
