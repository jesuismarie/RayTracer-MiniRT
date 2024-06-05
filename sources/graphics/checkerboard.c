/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:09:00 by mnazarya          #+#    #+#             */
/*   Updated: 2024/05/21 18:29:39 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static t_color	uv_pattern(t_vector pos, t_pattern pat, t_figure *obj)
{
	int			u_check;
	int			v_check;
	double		u;
	double		v;

	u = ((atan2(pos.x, pos.z) + M_PI) / 2 * M_PI) * pat.width / pat.height;
	v = (acos(pos.y) / M_PI);
	u_check = (int)(u * pat.width);
	v_check = (int)(v * pat.height);
	if ((u_check + v_check) % 2 == 0)
		return (pat.col);
	return (obj->color);
}

t_color	apply_checkerboard(t_figure *obj)
{
	t_vector	pos;
	t_pattern	checkerboard;

	checkerboard.col.r = 0;
	checkerboard.col.g = 0;
	checkerboard.col.b = 0;
	checkerboard.width = 5;
	checkerboard.height = 10;
	pos = obj->point.hit_norm;
	return (uv_pattern(pos, checkerboard, obj));
}
