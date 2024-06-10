/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:15:21 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/11 01:10:07 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_light	*new_light(t_vector coord, t_color col, double brightness)
{
	t_light	*light;

	light = ft_calloc(1, sizeof(t_light));
	error_exit(!light, MALLOC_ERR);
	light->color = col;
	light->brightness = brightness;
	light->coordinate = coord;
	light->next = NULL;
	return (light);
}


t_light *ft_light_push_back(t_light *start, t_light *obj)
{
	t_light	*new_obj;
	t_light	*tmp;

	new_obj = obj;
	tmp = start;
	if (!start)
		return (new_obj);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = obj;
	return (start);
}