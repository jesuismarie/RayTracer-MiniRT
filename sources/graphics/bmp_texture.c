/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 00:11:21 by mnazarya          #+#    #+#             */
/*   Updated: 2024/05/31 22:11:24 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	read_bmp(char *filename, t_bmp_map *texture)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
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
	return (1);
}

static void	check_bmp(int fd, t_bmp_map texture)
{
	if (texture.header.type != 0x4D42)
	{
		ft_printf("Not a bmp file\n");
		close(fd);
		return ;
	}
}

void	apply_texture(t_scene *scene)
{
	static int	i = -1;

	if (++i == 0)
	{
		;
		if (!read_bmp("resources/bmp/earth.bmp", &(scene->texture)))
		{
			ft_printf("Can't open bmp\n");
			return ;
		}
		check_bmp(scene->fd, scene->texture);
		lseek(scene->fd, scene->texture.header.data_offset, SEEK_SET);
		if (scene->texture.info_header.img_size == 0)
			scene->texture.info_header.img_size = \
				scene->texture.info_header.width \
				* abs( scene->texture.info_header.height) \
				* scene->texture.info_header.bpp / 8;
	}
}
