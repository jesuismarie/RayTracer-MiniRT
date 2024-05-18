/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:03:07 by mnazarya          #+#    #+#             */
/*   Updated: 2024/05/16 18:56:06 by mnazarya         ###   ########.fr       */
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

void	update_pixel_color(t_scene *scene, t_figure *obj, int *color, \
	t_vector ray)
{
	t_color		col;
	t_light		*tmp;

	*color = 0;
	if (!obj)
		return ;
	obj->point.rgb = obj->color;
	*color = rgb_to_hex(obj->color);
	if (obj && obj->type == LIGHT)
		return ;
	col = calc_rgb_light(scene->amb->light, scene->amb->ratio);
	tmp = scene->light;
	while (tmp)
	{
		if (compute_shadow(scene, ray, &obj, tmp))
		{
			col = add_rgb_light(diffuse_light(tmp, obj->point), col);
			col = add_rgb_light(specular_light(scene, tmp, obj), col);
		}
		tmp = tmp->next;
	}
	*color = rgb_to_hex(multiply_rgbs(col, obj->point.rgb));
}
