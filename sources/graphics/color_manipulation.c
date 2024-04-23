/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:43:58 by mnazarya          #+#    #+#             */
/*   Updated: 2024/04/22 15:22:14 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	rgb_to_hex(t_color rgb)
{
	int	color;

	color = (rgb.r << 16) | (rgb.g << 8) | rgb.b;
	return (color);
}

t_color	calc_rgb_light(t_color col, float ratio)
{
	t_color	rgb;

	rgb.r = col.r * ratio;
	rgb.g = col.g * ratio;
	rgb.b = col.b * ratio;
	if (rgb.r > 255)
		rgb.r = 255;
	if (rgb.g > 255)
		rgb.g = 255;
	if (rgb.b > 255)
		rgb.b = 255;
	return (rgb);
}

t_color	multiply_rgbs(t_color a, t_color b)
{
	t_color	color;

	color.r = a.r * b.r / 255;
	color.g = a.g * b.g / 255;
	color.b = a.b * b.b / 255;
	return (color);
}

t_color	add_rgb_light(t_color a, t_color b)
{
	t_color	color;

	color.r = a.r + b.r;
	color.g = a.g + b.g;
	color.b = a.b + b.b;
	if (color.r > 255)
		color.r = 255;
	if (color.g > 255)
		color.g = 255;
	if (color.b > 255)
		color.b = 255;
	return (color);
}
