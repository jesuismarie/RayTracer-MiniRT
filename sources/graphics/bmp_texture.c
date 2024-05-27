/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 00:11:21 by mnazarya          #+#    #+#             */
/*   Updated: 2024/05/27 22:05:59 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	check_bmp(int fd, t_bmp_map *texture)
{
	if (texture->header.type != 0x4D42)
	{
		ft_printf("Not a bmp file\n");
		close(fd);
		return ;
	}
}

void	read_bmp(char *filename, t_bmp_map *texture)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	
	read(fd, &texture->header.type, 2);
	read(fd, &texture->header.size, 4);
	read(fd, &texture->header.reserved, 4);
	read(fd, &texture->header.data_offset, 4);
	read(fd, &texture->info_header.head_size, 4);
	read(fd, &texture->info_header.width, 4);
	read(fd, &texture->info_header.height, 4);
	read(fd, &texture->info_header.planes, 2);
	read(fd, &texture->info_header.bpp, 2);
	read(fd, &texture->info_header.compression, 4);
	read(fd, &texture->info_header.img_size, 4);
	read(fd, &texture->info_header.horiz_res, 4);
	read(fd, &texture->info_header.vert_res, 4);
	read(fd, &texture->info_header.col_num, 4);
	read(fd, &texture->info_header.imp_col_num, 4);
	check_bmp(fd, texture);
}

void	apply_texture(t_scene *scene, char *filename)
{
	static int	i = 0;
	t_bmp_map	texture;

	if (scene->fd < 0 || read(scene->fd, NULL, 0) < 0)
	{
		ft_printf("Can't open bmp\n");
		return ;
	}
	if (++i == 0)
		read_bmp(filename, &texture);
}
