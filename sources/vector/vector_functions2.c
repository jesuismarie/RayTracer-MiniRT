/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 22:58:55 by mnazarya          #+#    #+#             */
/*   Updated: 2024/02/26 17:04:36 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	normalize_vector(t_vector vect)
{
	float	len;

	len = vector_len(vect);
	vect.x /= len;
	vect.y /= len;
	vect.z /= len;
}

float	vector_scalar_prod(t_vector v1, t_vector v2)
{
	float	res;

	res = ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
	return (res);
}
