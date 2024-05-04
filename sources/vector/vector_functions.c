/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:28:50 by mnazarya          #+#    #+#             */
/*   Updated: 2024/05/01 13:34:59 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vector	new_vector(double x, double y, double z)
{
	t_vector	new_vect;

	new_vect.x = x;
	new_vect.y = y;
	new_vect.z = z;
	return (new_vect);
}

t_vector	vector_sub(t_vector v1, t_vector v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}

t_vector	vector_sum(t_vector v1, t_vector v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

t_vector	vector_prod(t_vector vect, double n)
{
	vect.x *= n;
	vect.y *= n;
	vect.z *= n;
	return (vect);
}

double	vector_len(t_vector vect)
{
	double	len;

	len = sqrtf((vect.x * vect.x) + (vect.y * vect.y) + (vect.z * vect.z));
	return (len);
}
