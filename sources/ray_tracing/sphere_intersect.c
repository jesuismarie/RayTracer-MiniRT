/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:03:16 by mnazarya          #+#    #+#             */
/*   Updated: 2024/03/27 20:47:22 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

float	sphere_intersection(t_scene *scene, t_vector ray, t_sphere *sphere)
{
	t_equition	dot;
	t_vector	vec;

	vec = vector_sub(scene->cam->position, sphere->center);
	dot.a = 1;
	dot.b = 2 * vector_scalar_prod(vec, ray);
	dot.c = vector_scalar_prod(vec, vec) - (sphere->radius * sphere->radius);
	dot.discr = (dot.b * dot.b) - (4 * dot.a * dot.c);
	if (dot.discr < 0)
		return (0);
	dot.x1 = ((dot.b * (-1)) - sqrt(dot.discr)) / (2 * dot.a);
	dot.x2 = ((dot.b * (-1)) + sqrt(dot.discr)) / (2 * dot.a);
	if (dot.x1 > 0)
		return (1);
	return (0);
}
