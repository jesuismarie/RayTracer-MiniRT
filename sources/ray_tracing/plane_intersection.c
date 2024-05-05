/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:21:25 by mnazarya          #+#    #+#             */
/*   Updated: 2024/05/05 17:41:15 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	plane_intersection(t_vector pos, t_vector ray, t_figure **obj)
{
	double		dot;
	t_vector	vec;

	dot = vector_scalar_prod((*obj)->pln->norm, ray);
	if (fabs(dot) < __FLT_EPSILON__)
		return (0);
	vec = vector_sub((*obj)->pln->pos, pos);
	(*obj)->point.dist = vector_scalar_prod((*obj)->pln->norm, vec) / dot;
	if ((*obj)->point.dist < 0)
	{
		(*obj)->point.dist = 0;
		return (0);
	}
	return ((*obj)->point.dist);
}
