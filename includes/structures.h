/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:40:42 by mnazarya          #+#    #+#             */
/*   Updated: 2024/03/25 20:57:01 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef enum e_figure_type	t_figure_type;
typedef struct s_img		t_img;
typedef struct s_mlx		t_mlx;
typedef struct s_point		t_point;
typedef struct s_intersect	t_intersect;
typedef struct s_vector		t_vector;
typedef struct s_color		t_color;
typedef struct s_amb_light	t_amb_light;
typedef struct s_camera		t_camera;
typedef struct s_light		t_light;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;
typedef struct s_cone		t_cone;
typedef struct s_figure		t_figure;
typedef struct s_vplane		t_vplane;
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
	t_img	data;
};

struct s_point
{
	int	color;
};

struct s_intersect
{
	float	a;
	float	b;
	float	c;
	float	discr;
	float	x1;
	float	x2;
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
	int			fov;
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
	t_color		color;
	float		radius;
	float		spec;
};

struct s_plane
{
	t_vector	pos;
	t_vector	point;
	t_color		color;
	float		spec;
};

struct s_cylinder
{
	t_vector	center;
	t_vector	axis;
	t_color		color;
	float		radius;
	float		height;
	float		spec;
};

struct s_cone
{
	t_vector	coordinate;
	t_vector	axis;
	t_color		color;
	float		radius;
	float		height;
	float		spec;
};

struct s_figure
{
	t_sphere		*sph;
	t_plane			*pln;
	t_cylinder		*cyl;
	t_cylinder		*cone;
	t_figure_type	type;
	t_figure		*next;
};

struct s_vplane
{
	int		mlx_x;
	int		mlx_y;
	float	width;
	float	height;
	float	x_pixel;
	float	y_pixel;
	float	x_angle;
	float	y_angle;
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
