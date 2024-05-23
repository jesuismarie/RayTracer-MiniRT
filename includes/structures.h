/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:40:42 by mnazarya          #+#    #+#             */
/*   Updated: 2024/05/23 15:20:59 by mnazarya         ###   ########.fr       */
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
typedef struct s_pattern	t_pattern;
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
	LIGHT,
	SPHERE,
	CYLINDER,
	PLANE,
	CONE
};

struct s_img // don't touch
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l;
	int		end;
};

struct s_mlx // don't touch
{
	void	*mlx;
	void	*mlx_win;
	t_img	data;
};

struct s_equition // don't touch
{
	double	a;
	double	b;
	double	c;
	double	discr;
	double	x1;
	double	x2;
	double	m1;
	double	m2;
};

struct s_vector
{
	double	x;
	double	y;
	double	z;
};

struct s_color
{
	int	r;
	int	g;
	int	b;
};

struct s_amb_light
{
	double	ratio;
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
	double		brightness;
	t_vector	coordinate;
	t_color		color;
	t_light		*next;
};

struct s_pattern
{
	double	width;
	double	height;
	t_color	col;
};

struct s_sphere
{
	int			checkerboard;
	t_vector	center;
	double		radius;
};

struct s_plane
{
	t_vector	pos;
	t_vector	norm;
};

struct s_cylinder
{
	int			cap;
	t_vector	center;
	t_vector	axis;
	double		radius;
	double		height;
};

struct s_cone
{
	int			cap;
	t_vector	apex;
	t_vector	axis;
	double		radius;
	double		height;
	double		cos;
	double		sin;
};

struct s_intersect // don't touch
{
	int			is_inside;
	double		dist;
	t_color		rgb;
	t_vector	hit_pos;
	t_vector	hit_norm;
};

struct s_figure
{
	double			spec; // additional
	t_color			color;
	t_sphere		*sph;
	t_plane			*pln;
	t_cylinder		*cyl;
	t_cone			*cone;
	t_intersect		point; // don't touch
	t_figure_type	type;
	t_figure		*next;
};

struct s_vplane // don't touch
{
	int		mlx_x;
	int		mlx_y;
	double	width;
	double	height;
	double	x_pixel;
	double	y_pixel;
	double	x_angle;
	double	y_angle;
};

struct s_scene
{
	t_light		*light;
	t_figure	*figure;
	t_camera	*cam;
	t_amb_light	*amb;
	t_mlx		*mlx; // don't touch
	t_vplane	*view;
	double		height;
	double		width;
};

#endif
