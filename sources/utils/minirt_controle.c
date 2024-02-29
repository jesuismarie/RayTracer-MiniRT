/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_controle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:30:15 by mnazarya          #+#    #+#             */
/*   Updated: 2024/02/29 15:50:26 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	keys(int keycode, t_scene *scene)
{
	if (keycode == ESC)
	{
		// mlx_destroy_image(scene->mlx->mlx, scene->mlx->data->img);
		mlx_destroy_window(scene->mlx->mlx, scene->mlx->mlx_win);
		exit(0);
	}
	return (0);
}

int	close_win(t_scene *scene)
{
	// mlx_clear_window(scene->mlx->mlx, scene->mlx->mlx_win);
	mlx_destroy_window(scene->mlx->mlx, scene->mlx->mlx_win);
	exit(0);
}
