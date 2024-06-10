/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:21:25 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/08 17:44:36 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	plane_intersection(t_vector pos, t_vector ray, t_figure **obj)
{
	double		dot;
	t_vector	vec;

	(*obj)->point.dist = 0;
	dot = vector_scalar_prod((*obj)->pln->norm, ray);
	if (fabs(dot) < __FLT_EPSILON__)
		return (INFINITY);
	vec = vector_sub((*obj)->pln->pos, pos);
	(*obj)->point.dist = vector_scalar_prod((*obj)->pln->norm, vec) / dot;
	if ((*obj)->point.dist < __FLT_EPSILON__)
	{
		(*obj)->point.dist = 0;
		return (INFINITY);
	}
	return ((*obj)->point.dist);
}
