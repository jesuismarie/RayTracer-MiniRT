/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:30:15 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/12 19:42:57 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	clear_window(t_scene *scene)
{
	int	i;
	int	j;

	i = 0;
	while (i < scene->height)
	{
		j = 0;
		while (j < scene->width)
		{
			my_mlx_pixel_put(scene, i, j, rgb_to_hex(new_color(0, 0, 0)));
			j++;
		}
		i++;
	}
}

static void	check_bump_texture(int keycode, t_scene *scene)
{
	t_figure	*start;

	start = NULL;
	if (keycode == KEY_B)
	{
		start = scene->figure;
		while (start)
		{
			if (start->type == SPHERE)
				start->sph->bump = !start->sph->bump;
			start = start->next;
		}
		event_thread(scene, 'b');
	}
	else if (keycode == KEY_T)
	{
		start = scene->figure;
		while (start)
		{
			if (start->type == SPHERE)
				start->sph->texture = !start->sph->texture;
			start = start->next;
		}
		event_thread(scene, 't');
	}
}

int	key_press(int keycode, t_scene *scene)
{
	t_figure	*start;

	start = NULL;
	if (keycode == ESC)
		close_win(scene);
	else if (keycode == KEY_C)
	{
		start = scene->figure;
		while (start)
		{
			if (start->type == SPHERE)
				start->sph->checkerboard = !start->sph->checkerboard;
			start = start->next;
		}
		event_thread(scene, 'c');
	}
	else
		check_bump_texture(keycode, scene);
	return (0);
}

int	close_win(t_scene *scene)
{
	mlx_clear_window(scene->mlx->mlx, scene->mlx->mlx_win);
	mlx_destroy_window(scene->mlx->mlx, scene->mlx->mlx_win);
	clear_scene(scene);
	exit(0);
}
