/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:40:42 by mnazarya          #+#    #+#             */
/*   Updated: 2024/02/24 20:34:33 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}	t_mlx;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_amb_light
{
	t_color	light;
	float	ratio;
}	t_amb_light;

typedef struct s_camera
{
	t_vector	dir;
	t_vector	position;
	int			degree;
}	t_camera;

typedef struct s_light
{
	t_vector	coordinate;
	t_color		color;
	float		brightness;
}	t_light;

typedef struct s_sphere
{
	t_vector	center;
	float		d;
	t_color		color;
}	t_sphere;

typedef struct s_plane
{
	t_vector	point;
	t_vector	pos;
	t_color		color;
}	t_plane;

typedef struct s_cylinder
{
	t_vector	center;
	t_vector	axis;
	float		d;
	float		h;
	t_color		color;
}	t_cylinder;

typedef struct s_minirt
{
	t_amb_light	*amb;
	t_light		*light;
	t_camera	*cam;
	t_mlx		*mlx;
	t_vector	ray;
	float		x_angle;
	float		y_angle;
	int			check;
	float		height;
	float		width;
}	t_minirt;

#endif
