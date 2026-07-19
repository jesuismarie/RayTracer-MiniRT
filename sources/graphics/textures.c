/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <mnazarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:52:20 by mnazarya          #+#    #+#             */
/*   Updated: 2026/07/19 12:08:58 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_img	get_pattern(t_scene *scene, char *filename, int flag)
{
	t_img	texture;

	ft_memset(&texture, 0, sizeof(t_img));
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

t_img	load_xpm_image(t_scene *scene, char *filename)
{
	t_img	img;

	ft_memset(&img, 0, sizeof(t_img));
	if (!filename)
		return (img);
	img.img = mlx_xpm_file_to_image(scene->mlx->mlx, filename, \
		&img.width, &img.height);
	if (img.img)
		img.addr = mlx_get_data_addr(img.img, &img.bpp, \
			&img.l, &img.end);
	if (!img.img || !img.addr)
		ft_printf("Failed to load: %s\n", filename);
	return (img);
}
static void	get_sphere_uv(t_vector pos, t_img img, double *u, double *v)
{
	*u = (atan2(pos.z, pos.x) + M_PI) / (2 * M_PI) * img.width;
	*v = acos(pos.y) / M_PI * img.height;
	if (*u < 0)
		*u = 0;
	else if (*u >= img.width)
		*u = img.width - 1;
	if (*v < 0)
		*v = 0;
	else if (*v >= img.height)
		*v = img.height - 1;
}

t_color	apply_texture(t_scene *scene, t_figure *obj)
{
	double	u;
	double	v;
	t_img	tex;

	tex = scene->texture;
	if (obj->sph->texture_path && obj->sph->texture_img.img)
		tex = obj->sph->texture_img;
	else if (!(scene->f_texture))
		return (obj->point.rgb);
	if (!tex.img || !tex.addr)
		return (obj->point.rgb);
	get_sphere_uv(obj->point.hit_norm, tex, &u, &v);
	return (hex_to_rgb(my_mlx_pixel_get(tex, (int)u, (int)v)));
}

t_vector	apply_bump(t_scene *scene, t_figure *obj)
{
	double		u;
	double		v;
	t_vector	bump;
	t_img		bmp;

	bmp = scene->bump;
	if (obj->sph->bump_path && obj->sph->bump_img.img)
		bmp = obj->sph->bump_img;
	else if (!(scene->f_bump))
		return (obj->point.hit_norm);
	if (!bmp.img || !bmp.addr)
		return (obj->point.hit_norm);
	get_sphere_uv(obj->point.hit_norm, bmp, &u, &v);
	bump = rgb_to_norm_vec(hex_to_rgb(my_mlx_pixel_get(bmp, (int)u, (int)v)));
	bump = vector_sum(obj->point.hit_norm, bump);
	normalize_vector(&bump);
	return (bump);
}
