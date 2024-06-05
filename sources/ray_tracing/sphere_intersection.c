/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:03:16 by mnazarya          #+#    #+#             */
/*   Updated: 2024/05/23 15:52:53 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	sphere_intersection(t_vector pos, t_vector ray, t_figure **obj)
{
	t_equition	dot;
	t_vector	vec;

	vec = vector_sub(pos, (*obj)->sph->center);
	dot.a = vector_len(ray) * vector_len(ray);
	dot.b = 2 * vector_scalar_prod(vec, ray);
	dot.c = vector_len(vec) * vector_len(vec) - (*obj)->sph->radius \
		* (*obj)->sph->radius;
	dot.discr = pow(dot.b, 2) - (4 * dot.a * dot.c);
	if (dot.discr < 0)
		return (0);
	dot.x1 = ((dot.b * (-1)) - sqrt(dot.discr)) / (2 * dot.a);
	dot.x2 = ((dot.b * (-1)) + sqrt(dot.discr)) / (2 * dot.a);
	find_hit_distance(obj, dot);
	return ((*obj)->point.dist);
}
