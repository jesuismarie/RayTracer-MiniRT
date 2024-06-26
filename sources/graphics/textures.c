/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:52:20 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/04 23:50:27 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_img	get_pattern(t_scene *scene, char *filename, int flag)
{
	t_img	texture;

	if (filename)
		texture.img = mlx_xpm_file_to_image(scene->mlx->mlx, filename, \
			&texture.width, &texture.height);
	if (texture.img)
		texture.addr = mlx_get_data_addr(texture.img, &texture.bpp, \
			&texture.l, &texture.end);
	if (!texture.img || !texture.addr)
	{
		if (flag)
			scene->f_bump = 0;
		else
			scene->f_texture = 0;
		ft_printf("Failed to load texture file\n");
		return (texture);
	}
	if (flag)
		scene->f_bump = 1;
	else
		scene->f_texture = 1;
	return (texture);
}

t_color	apply_texture(t_scene *scene, t_figure *obj)
{
	double		u;
	double		v;
	t_vector	pos;

	if (!(scene->f_texture))
		return (obj->point.rgb);
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
	t_vector	bump;

	if (!(scene->f_bump))
		return (obj->point.hit_norm);
	pos = obj->point.hit_norm;
	u = 150 * ((atan2(pos.x, pos.z) + M_PI) / 2 * M_PI) \
		* scene->bump.width / scene->bump.height;
	v = 300 * (acos(pos.y) / M_PI);
	bump = rgb_to_norm_vec(hex_to_rgb(my_mlx_pixel_get(scene->bump, u, v)));
	bump = vector_sum(pos, bump);
	normalize_vector(&bump);
	return (bump);
}
