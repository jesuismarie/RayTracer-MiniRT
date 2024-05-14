/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:39:35 by mnazarya          #+#    #+#             */
/*   Updated: 2024/05/05 16:44:16 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_plane	*new_plane(t_vector pos, t_vector norm)
{
	t_plane	*pln;

	pln = ft_calloc(1, sizeof(t_plane));
	error_exit(!pln, MALLOC_ERR);
	pln->pos = pos;
	pln->norm = norm;
	return (pln);
}
