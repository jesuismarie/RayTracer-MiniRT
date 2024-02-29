/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:40:42 by mnazarya          #+#    #+#             */
/*   Updated: 2024/02/29 16:04:16 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef enum e_figure_type	t_figure_type;
typedef struct s_img		t_img;
typedef struct s_mlx		t_mlx;
typedef struct s_vector		t_vector;
typedef struct s_color		t_color;
typedef struct s_amb_light	t_amb_light;
typedef struct s_camera		t_camera;
typedef struct s_light		t_light;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;
typedef struct s_figure		t_figure;
typedef struct s_scene		t_scene;

enum e_figure_type
{
	SPHERE,
	CYLINDER,
	PLANE,
	CONE
};

struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l;
	int		end;
};

struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	t_img	*data;
};

struct s_vector
{
	float	x;
	float	y;
	float	z;
};

struct s_color
{
	int	r;
	int	g;
	int	b;
};

struct s_amb_light
{
	t_color	light;
	float	ratio;
};

struct s_camera
{
	t_vector	dir;
	t_vector	position;
	int			degree;
};

struct s_light
{
	t_vector	coordinate;
	t_color		color;
	float		brightness;
	t_light		*next;
};

struct s_sphere
{
	t_vector	center;
	float		r;
};

struct s_plane
{
	t_vector	point;
	t_vector	pos;
};

struct s_cylinder
{
	t_vector	center;
	t_vector	axis;
	float		r;
	float		h;
};

struct s_figure
{
	t_sphere		*sph;
	t_plane			*pln;
	t_cylinder		*cyl;
	t_color			color;
	float			spec;
	t_figure_type	type;
	t_figure		*next;
};

struct s_scene
{
	t_amb_light	*amb;
	t_light		*light;
	t_camera	*cam;
	t_figure	*figure;
	t_mlx		*mlx;
	float		height;
	float		width;
};

#endif
