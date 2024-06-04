/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:03:07 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/04 23:03:12 by mnazarya         ###   ########.fr       */
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

unsigned int	my_mlx_pixel_get(t_img img, int x, int y)
{
	char	*dst;

	dst = img.addr + (y * img.l + x * (img.bpp / 8));
	return (*(unsigned int *)dst);
}

void	update_pixel_color(t_scene *scene, t_vector ray, t_figure *obj, \
	int *color)
{
	t_color	col;
	t_color	spec;

	if (!obj)
		return ;
	obj->point.rgb = obj->color;
	obj->point.hit_pos = vector_sum(scene->cam->pos, vector_prod(ray, \
		obj->point.dist));
	set_hit_normal(&obj, ray);
	if (obj->type == SPHERE && obj->sph && obj->sph->checkerboard)
		obj->point.rgb = apply_checkerboard(obj);
	if (obj->type == SPHERE && obj->sph && obj->sph->texture)
		obj->point.rgb = apply_texture(scene, obj);
	if (obj->type == SPHERE && obj->sph && obj->sph->bump)
		obj->point.hit_norm = apply_bump(scene, obj);
	*color = rgb_to_hex(obj->color);
	spec = new_color(0, 0, 0);
	if (obj && obj->type == LIGHT)
		return ;
	col = compute_light(scene, obj, &spec);
	*color = rgb_to_hex(add_rgb_light(multiply_rgbs(col, \
		obj->point.rgb), spec));
}
