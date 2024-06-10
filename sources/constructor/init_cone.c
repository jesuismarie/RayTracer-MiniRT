/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:34:01 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/10 12:49:07 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_cone	*new_cone(t_vector coord, t_vector axis, double r, double h)
{
	double	hypotenuse;
	t_cone	*cone;

	cone = ft_calloc(1, sizeof(t_cone));
	error_exit(!cone, MALLOC_ERR);
	cone->center = coord;
	cone->axis = axis;
	cone->radius = r;
	cone->height = h;
	cone->cap = 0;
	hypotenuse = sqrt(pow(cone->radius, 2) \
		+ pow(cone->height, 2));
	cone->cos = cone->height / hypotenuse;
	cone->sin = cone->radius / hypotenuse;
	cone->apex = vector_sum(cone->center, \
		vector_prod(cone->axis, cone->height));
	return (cone);
}
