/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <mnazarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:47:04 by gehovhan          #+#    #+#             */
/*   Updated: 2026/07/18 19:14:53 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool	ft_validate_sphere_args(t_sphere sphere, char **error)
{
	if (!ft_validate_color(sphere.color_p, error))
		return (set_error(error, ft_format_error(__func__, "")));
	return (true);
}

static int	ft_sp_num_count(t_list_token *list)
{
	int		size;
	t_token	*tmp;

	size = 0;
	tmp = list->head->next;
	while (tmp)
	{
		if (is_digit_float(tmp->token))
			size++;
		tmp = tmp->next;
	}
	return (size);
}

bool	ft_parse_sp_optional_arg(t_sphere *sphere, \
	t_list_token *list, t_token **start, char **error)
{
	int	count;

	(void)error;
	count = ft_sp_num_count(list);
	if (count == SPHERE_MAX_ARGS + 1)
	{
		*start = ft_jump(*start, 1);
		sphere->spec_p = ft_atof((*start)->token);
		if (sphere->spec_p < 0)
			return (set_error(error, ft_format_error(__func__, "")));
	}
	return (true);
}

static void	ft_parse_sp_paths(t_list_token *list, t_sphere *sphere)
{
	t_token	*tmp;
	int		len;

	sphere->texture_path = NULL;
	sphere->bump_path = NULL;
	tmp = list->tail;
	if (!tmp || !tmp->token)
		return ;
	len = ft_strlen(tmp->token);
	if (len < 5 || ft_strcmp_std(tmp->token + len - 4, ".xpm") != 0)
		return ;
	if (tmp->prev && tmp->prev->token)
	{
		len = ft_strlen(tmp->prev->token);
		if (len >= 5 && ft_strcmp_std(tmp->prev->token + len - 4, \
			".xpm") == 0)
		{
			sphere->texture_path = ft_strdup(tmp->prev->token);
			sphere->bump_path = ft_strdup(tmp->token);
			return ;
		}
	}
	sphere->texture_path = ft_strdup(tmp->token);
}

bool	ft_parse_sphere(t_list_token *list, t_sphere *sphere, char **error)
{
	t_token		*tmp;

	tmp = list->head;
	sphere->center = ft_parse_pos(tmp);
	tmp = ft_jump(tmp, 6);
	sphere->radius = ft_atof(tmp->token);
	if (sphere->radius < 0)
		return (set_error(error, ft_format_error(__func__, "")));
	sphere->radius /= 2;
	if (!ft_parse_sp_optional_arg(sphere, list, &tmp, error))
		return (set_error(error, ft_format_error(__func__, "")));
	sphere->color_p = ft_parse_color(tmp);
	ft_parse_sp_paths(list, sphere);
	return (true);
}

bool	ft_create_sphere(t_scene *scene, t_list_token *list, char **error)
{
	t_sphere	sphere;
	t_sphere	*new_obj;

	ft_memset(&sphere, 0, sizeof(t_sphere));
	if (!ft_parse_sphere(list, &sphere, error))
		return (set_error(error, ft_format_error(__func__, "")));
	if (!ft_validate_sphere_args(sphere, error))
		return (set_error(error, ft_format_error(__func__, "")));
	new_obj = new_sphere(sphere.center, sphere.radius);
	new_obj->color_p = sphere.color_p;
	new_obj->spec_p = sphere.spec_p;
	new_obj->texture_path = sphere.texture_path;
	new_obj->bump_path = sphere.bump_path;
	if (sphere.texture_path)
		new_obj->texture = 1;
	if (sphere.bump_path)
		new_obj->bump = 1;
	scene->figure = ft_push_back_obj(scene->figure, \
		new_figure(new_obj, SPHERE));
	return (true);
}
