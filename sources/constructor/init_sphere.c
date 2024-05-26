/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:07:01 by mnazarya          #+#    #+#             */
/*   Updated: 2024/05/26 21:24:55 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_sphere	*new_sphere(t_vector center, double r)
{
	t_sphere	*sph;

	sph = ft_calloc(1, sizeof(t_sphere));
	error_exit(!sph, MALLOC_ERR);
	sph->checkerboard = 0;
	sph->texture = 0;
	sph->center = center;
	sph->radius = r;
	return (sph);
}
