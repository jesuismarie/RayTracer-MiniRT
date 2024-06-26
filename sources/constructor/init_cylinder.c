/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:22:41 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/09 18:47:15 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_cylinder	*new_cylinder(t_vector center, t_vector axis, double r, double h)
{
	t_cylinder	*cyl;

	cyl = ft_calloc(1, sizeof(t_cylinder));
	error_exit(!cyl, MALLOC_ERR);
	cyl->center = center;
	cyl->axis = axis;
	cyl->radius = r;
	cyl->height = h;
	cyl->flag = 0;
	cyl->cap = 0;
	cyl->center1 = vector_sum(cyl->center, \
		vector_prod(cyl->axis, cyl->height));
	return (cyl);
}
