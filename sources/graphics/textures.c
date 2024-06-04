/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:52:20 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/04 14:28:37 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_img	get_pattern(t_scene *scene, char *filename)
{
	t_img	texture;

	if (filename)
		texture.img = mlx_xpm_file_to_image(scene->mlx->mlx, filename, \
			&texture.width, &texture.height);
	if (texture.img)
		texture.addr = mlx_get_data_addr(texture.img, &texture.bpp, \
			&texture.l, &texture.end);
	if (!texture.img || !texture.addr)
		ft_printf("Failed to load texture file\n");
	return (texture);
}

t_color	apply_texture(t_scene *scene, t_figure *obj)
{
	double		u;
	double		v;
	t_vector	pos;

	pos = obj->point.hit_norm;
	u = 150 * ((atan2(pos.x, pos.z) + M_PI) / 2 * M_PI) \
		* scene->texture.width / scene->texture.height;
	v = 300 * (acos(pos.y) / M_PI);
	return (hex_to_rgb(my_mlx_pixel_get(scene->texture, u, v)));
}

t_vector	apply_bump(t_scene *scene, t_figure *obj)
{
	double		u;
	double		v;
	t_vector	pos;

	pos = obj->point.hit_norm;
	u = 150 * ((atan2(pos.x, pos.z) + M_PI) / 2 * M_PI) \
		* scene->bump.width / scene->bump.height;
	v = 300 * (acos(pos.y) / M_PI);
	return (rgb_to_norm_vec(hex_to_rgb(my_mlx_pixel_get(scene->bump, u, v))));
}
