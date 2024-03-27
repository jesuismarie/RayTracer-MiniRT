/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_amb_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:45:20 by mnazarya          #+#    #+#             */
/*   Updated: 2024/03/26 17:09:38 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_amb_light	*new_amb_light(t_color col, float ratio)
{
	t_amb_light	*amb_light;

	amb_light = ft_calloc(1, sizeof(t_amb_light));
	amb_light->light = col;
	amb_light->ratio = ratio;
	return (amb_light);
}
