/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:39:17 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/04 23:48:18 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_color	new_color(int r, int g, int b)
{
	t_color	col;

	col.r = r;
	col.g = g;
	col.b = b;
	return (col);
}

int	rgb_to_hex(t_color rgb)
{
	int	color;

	color = (rgb.r << 16) | (rgb.g << 8) | rgb.b;
	return (color);
}

t_color	hex_to_rgb(unsigned int col)
{
	t_color	rgb;

	rgb.r = (col & 0x00ff0000) >> 16;
	rgb.g = (col & 0x0000ff00) >> 8;
	rgb.b = (col & 0x000000ff);
	return (rgb);
}

t_vector	rgb_to_norm_vec(t_color rgb)
{
	t_vector	norm;

	norm.x = (rgb.r / 255.0) * 2 - 1;
	norm.y = (rgb.g / 255.0) * 2 - 1;
	norm.z = (rgb.b / 255.0) * 2 - 1;
	normalize_vector(&norm);
	return (norm);
}
