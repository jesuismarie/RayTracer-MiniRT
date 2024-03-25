/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:03:07 by mnazarya          #+#    #+#             */
/*   Updated: 2024/03/25 20:43:39 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	rgb_to_hex(t_figure *obj)
{
	int		color;
	t_color	rgb;

	if (obj->type == PLANE)
		rgb = obj->pln->color;
	else if (obj->type == SPHERE)
		rgb = obj->sph->color;
	else if (obj->type == CYLINDER)
		rgb = obj->cyl->color;
	else if (obj->type == CONE)
		rgb = obj->cone->color;
	color = (rgb.r << 16) | (rgb.g << 16) | (rgb.b << 16);
	return (color);
}

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
