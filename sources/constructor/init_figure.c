/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:14:21 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/11 21:12:23 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	new_figure_helper(void *obj, t_figure_type type, \
	t_figure **figure)
{
	if (type == PLANE)
	{
		(*figure)->pln = obj;
		(*figure)->spec = ((t_plane *)obj)->spec_p;
		(*figure)->color = ((t_plane *)obj)->color_p;
	}
	else if (type == CYLINDER)
	{
		(*figure)->cyl = obj;
		(*figure)->spec = ((t_cylinder *)obj)->spec_p;
		(*figure)->color = ((t_cylinder *)obj)->color_p;
	}
	else if (type == CONE)
	{
		(*figure)->cone = obj;
		(*figure)->spec = ((t_cone *)obj)->spec_p;
		(*figure)->color = ((t_cone *)obj)->color_p;
	}
	else
	{
		free(*figure);
		*figure = NULL;
	}
}

t_figure	*new_figure(void *obj, t_figure_type type)
{
	t_figure	*figure;

	figure = ft_calloc(1, sizeof(t_figure));
	figure->type = type;
	if (type == LIGHT)
	{
		figure->sph = obj;
		figure->color = ((t_sphere *)obj)->color_p;
	}
	else if (type == SPHERE)
	{
		figure->sph = obj;
		figure->spec = ((t_sphere *)obj)->spec_p;
		figure->color = ((t_sphere *)obj)->color_p;
	}
	else
		new_figure_helper(obj, type, &figure);
	if (figure && ft_is_near_equal(figure->spec, 0))
		figure->spec = 100;
	return (figure);
}

t_figure	*ft_get_last_obj(t_figure *start)
{
	if (!start)
		return (NULL);
	while (start->next)
		start = start->next;
	return (start);
}

t_figure	*ft_push_back_obj(t_figure *start, t_figure *obj)
{
	t_figure	*new_obj;
	t_figure	*tmp;

	new_obj = obj;
	tmp = start;
	if (!start)
		return (new_obj);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = obj;
	return (start);
}
