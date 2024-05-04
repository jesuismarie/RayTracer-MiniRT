/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 22:58:55 by mnazarya          #+#    #+#             */
/*   Updated: 2024/05/01 13:34:59 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	normalize_vector(t_vector *vect)
{
	double	len;

	len = vector_len(*vect);
	vect->x /= len;
	vect->y /= len;
	vect->z /= len;
}

double	vector_scalar_prod(t_vector v1, t_vector v2)
{
	double	res;

	res = ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
	return (res);
}

t_vector	vector_cross(t_vector v1, t_vector v2)
{
	t_vector	res;

	res.x = v1.y * v2.z - v1.z * v2.y;
	res.y = v1.z * v2.x - v1.x * v2.z;
	res.z = v1.x * v2.y - v1.y * v2.x;
	return (res);
}
