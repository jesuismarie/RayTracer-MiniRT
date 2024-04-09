/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:40:42 by mnazarya          #+#    #+#             */
/*   Updated: 2024/04/04 20:54:09 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef enum e_figure_type	t_figure_type;
typedef struct s_img		t_img;
typedef struct s_mlx		t_mlx;
typedef struct s_equition	t_equition;
typedef struct s_vector		t_vector;
typedef struct s_color		t_color;
typedef struct s_amb_light	t_amb_light;
typedef struct s_camera		t_camera;
typedef struct s_light		t_light;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;
typedef struct s_cone		t_cone;
typedef struct s_intersect	t_intersect;
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

struct s_equition
{
	float	a;
	float	b;
	float	c;
	float	discr;
	float	x1;
	float	x2;
	float	m1;
	float	m2;
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
	float	ratio;
	t_color	light;
};

struct s_camera
{
	int			fov;
	t_vector	pos;
	t_vector	norm;
};

struct s_light
{
	float		brightness;
	t_vector	coordinate;
	t_color		color;
	t_light		*next;
};

struct s_sphere
{
	t_vector	center;
	float		radius;
};

struct s_plane
{
	t_vector	pos;
	t_vector	point;
};

struct s_cylinder
{
	t_vector	center;
	t_vector	axis;
	float		radius;
	float		height;
};

struct s_cone
{
	t_vector	coordinate;
	t_vector	axis;
	float		radius;
	float		height;
};

struct s_intersect
{
	int			is_inside;
	int			color;
	float		dist;
	t_color		rgb;
	t_vector	hit_pos;
	t_vector	hit_norm;
	t_vector	light_dir;
};

struct s_figure
{
	float			spec;
	t_color			color;
	t_sphere		*sph;
	t_plane			*pln;
	t_cylinder		*cyl;
	t_cylinder		*cone;
	t_intersect		point;
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
	t_mlx		*mlx;
	t_light		*light;
	t_camera	*cam;
	t_vplane	*view;
	t_figure	*figure;
	t_amb_light	*amb;
	float		height;
	float		width;
};

#endif
