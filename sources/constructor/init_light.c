/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:15:21 by mnazarya          #+#    #+#             */
/*   Updated: 2024/04/02 20:23:27 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_light	*new_light(t_vector coord, t_color col, float brightness)
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
