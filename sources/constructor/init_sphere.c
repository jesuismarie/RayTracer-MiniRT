/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:07:01 by mnazarya          #+#    #+#             */
/*   Updated: 2024/03/31 19:13:34 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_sphere	*new_sphere(t_vector center, float r)
{
	t_sphere	*sph;

	sph = ft_calloc(1, sizeof(t_sphere));
	error_exit(!sph, MALLOC_ERR);
	sph->center = center;
	sph->radius = r;
	return (sph);
}
