/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:03:07 by mnazarya          #+#    #+#             */
/*   Updated: 2024/05/26 21:26:09 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	my_mlx_pixel_put(t_scene *scene, int x, int y, int color)
{
	char	*dst;

	if (scene->mlx->data.addr && x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		dst = scene->mlx->data.addr + (y * scene->mlx->data.l + x * \
			(scene->mlx->data.bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	update_pixel_color(t_scene *scene, t_vector ray, t_figure *obj, \
	int *color)
{
	t_color	col;
	t_color	spec;

	if (!obj)
		return ;
	obj->point.rgb = obj->color;
	if (obj->type == SPHERE && obj->sph && obj->sph->checkerboard)
		obj->point.rgb = apply_checkerboard(obj);
	// if (obj->type == SPHERE && obj->sph && obj->sph->texture)
	// 	obj->point.rgb = ;
	*color = rgb_to_hex(obj->color);
	spec = new_color(0, 0, 0);
	if (obj && obj->type == LIGHT)
		return ;
	col = compute_light(scene, ray, obj, &spec);
	*color = rgb_to_hex(add_rgb_light(multiply_rgbs(col, \
		obj->point.rgb), spec));
}
