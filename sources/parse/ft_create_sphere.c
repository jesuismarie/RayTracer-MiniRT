/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:47:04 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/10 18:31:14 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool	ft_validate_sphere_args(t_sphere sphere, char **error)
{
	if (!ft_validate_color(sphere.color_p, error))
		return (set_error(error, ft_format_error(__func__, "")));
	return (true);
}

bool	ft_parse_sp_optional_arg(t_sphere *sphere, \
	t_list_token *list, t_token **start, char **error)
{
	int	count;

	count = ft_args_count(list, error);
	if (count == -1)
		return (set_error(error, ft_format_error(__func__, "")));
	if (count == SPHERE_MAX_ARGS + 1)
	{
		*start = ft_jump(*start, 1);
		printf("%s\n", (*start)->token);
		sphere->spec_p = ft_atof((*start)->token);
		if (ft_is_near_equal(sphere->spec_p, 0) || sphere->spec_p < 0)
			return (set_error(error, ft_format_error(__func__, "")));
	}
	return (true);
}

bool	ft_parse_sphere(t_list_token *list, \
	t_sphere *sphere, char **error)
{
	t_token		*tmp;

	tmp = ft_jump(list->head, 1);
	sphere->center = ft_parse_pos(tmp);
	tmp = ft_jump(tmp, 5);
	sphere->radius = ft_atof(tmp->token);
	if (sphere->radius < 0)
		return (set_error(error, ft_format_error(__func__, "")));
	sphere->radius /= 2;
	if (!ft_parse_sp_optional_arg(sphere, list, &tmp, error))
		return (set_error(error, ft_format_error(__func__, "")));
	sphere->color_p = ft_parse_color(tmp);
	return (true);
}

bool	ft_create_sphere(t_scene *scene, t_list_token	*list, char **error)
{
	t_sphere	*sphere;

	sphere = ft_calloc(1, sizeof(t_sphere));
	if (!ft_parse_sphere(list, sphere, error))
		return (set_error(error, ft_format_error(__func__, "")));
	if (!ft_validate_sphere_args(*sphere, error))
		return (set_error(error, ft_format_error(__func__, "")));
	scene->figure = ft_push_back_obj(scene->figure, new_figure(sphere, SPHERE));
	return (true);
}
