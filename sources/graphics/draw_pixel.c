/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:03:07 by mnazarya          #+#    #+#             */
/*   Updated: 2024/05/07 22:42:21 by gehovhan         ###   ########.fr       */
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
