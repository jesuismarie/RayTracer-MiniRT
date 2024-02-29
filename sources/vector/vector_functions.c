/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:28:50 by mnazarya          #+#    #+#             */
/*   Updated: 2024/02/26 00:02:19 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_vector	new_vector(float x, float y, float z)
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

t_vector	vector_prod(t_vector vect, float n)
{
	vect.x *= n;
	vect.y *= n;
	vect.z *= n;
	return (vect);
}

float	vector_len(t_vector vect)
{
	float	len;

	len = sqrt((vect.x * vect.x) + (vect.y * vect.y) + (vect.z * vect.z));
	return (len);
}
