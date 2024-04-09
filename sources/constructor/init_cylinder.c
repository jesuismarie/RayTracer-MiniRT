/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:22:41 by mnazarya          #+#    #+#             */
/*   Updated: 2024/03/31 19:13:26 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_cylinder	*new_cylinder(t_vector center, t_vector axis, float r, float h)
{
	t_cylinder	*cyl;

	cyl = ft_calloc(1, sizeof(t_cylinder));
	error_exit(!cyl, MALLOC_ERR);
	cyl->center = center;
	cyl->axis = axis;
	cyl->radius = r;
	cyl->height = h;
	return (cyl);
}
