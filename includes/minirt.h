/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:05:56 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/04 17:18:53 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <mlx.h>
# include <math.h>
# include <libft.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <defines.h>
# include <ft_printf.h>
# include <structures.h>

/*----------------------------------------------------------------------------*/
/*---------------------------------- PARSER ----------------------------------*/
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*---------------------------- INIT & CONSTRUCTOR ----------------------------*/
/*----------------------------------------------------------------------------*/
void			init_scene(t_scene **scene);
void			win_init(t_scene **scene);
void			img_init(t_scene *scene);
t_camera		*new_camera(t_vector pos, t_vector dir, int fov);
t_light			*new_light(t_vector coord, t_color col, double brightness);
t_amb_light		*new_amb_light(t_color col, double ratio);
t_sphere		*new_sphere(t_vector center, double r);
t_plane			*new_plane(t_vector pos, t_vector norm);
t_cylinder		*new_cylinder(t_vector center, t_vector axis, double r, \
					double h);
t_cone			*new_cone(t_vector coord, t_vector axis, double r, double h);

/*----------------------------------------------------------------------------*/
/*---------------------------------- VECTOR ----------------------------------*/
/*----------------------------------------------------------------------------*/
t_vector		new_vector(double x, double y, double z);
t_vector		vector_sub(t_vector vect1, t_vector vect2);
t_vector		vector_sum(t_vector vect1, t_vector vect2);
t_vector		vector_prod(t_vector vect, double n);
t_vector		vector_cross(t_vector v1, t_vector v2);
double			vector_len(t_vector vect);
void			normalize_vector(t_vector *vect);
double			vector_scalar_prod(t_vector v1, t_vector v2);
t_vector		vector_rotate_cw(t_vector vect);
t_vector		vector_rotate_ccw(t_vector vect);

/*----------------------------------------------------------------------------*/
/*--------------------------------- GRAPHICS ---------------------------------*/
/*----------------------------------------------------------------------------*/
t_color			new_color(int r, int g, int b);
int				rgb_to_hex(t_color rgb);
t_color			hex_to_rgb(unsigned int col);
t_vector		rgb_to_norm_vec(t_color rgb);
t_color			calc_rgb_light(t_color col, double ratio);
t_color			multiply_rgbs(t_color a, t_color b);
t_color			add_rgb_light(t_color a, t_color b);
t_img			get_pattern(t_scene *scene, char *filename, int flag);
t_color			apply_checkerboard(t_figure *obj);
t_color			apply_texture(t_scene *scene, t_figure *obj);
t_vector		apply_bump(t_scene *scene, t_figure *obj);
t_color			diffuse_light(t_light *light, t_intersect point);
t_color			specular_light(t_scene *scene, t_light *light, t_figure *obj);
void			update_pixel_color(t_scene *scene, t_vector ray, t_figure *obj, \
					int *color);
t_color			compute_light(t_scene *scene, t_figure *obj, \
					t_color *spec);
int				compute_shadow(t_scene *scene, t_figure **obj, \
					t_light *light);
void			my_mlx_pixel_put(t_scene *scene, int x, int y, int color);
unsigned int	my_mlx_pixel_get(t_img img, int x, int y);

/*----------------------------------------------------------------------------*/
/*------------------------------- RAY TRACING --------------------------------*/
/*----------------------------------------------------------------------------*/
t_vplane		*get_view_plane(t_scene *scene);
t_vector		look_at(t_scene	*scene, double ray_x, double ray_y);
void			trace_ray(t_scene *scene);
double			sphere_intersection(t_vector pos, t_vector ray, \
					t_figure **obj);
double			plane_intersection(t_vector pos, t_vector ray, t_figure **obj);
double			cylinder_intersection(t_vector pos, t_vector ray, \
					t_figure **obj);
double			cone_intersection(t_vector pos, t_vector ray, t_figure **obj);
double			check_intersection(t_vector pos, t_vector ray, \
					t_figure **obj, int light);
void			object_intersection(t_scene *scene, t_vector ray, int *color);

/*----------------------------------------------------------------------------*/
/*--------------------------------- CONTROL ----------------------------------*/
/*----------------------------------------------------------------------------*/
int				keys(int keycode, t_scene *scene);
int				close_win(t_scene *scene);

/*----------------------------------------------------------------------------*/
/*---------------------------------- UTILS -----------------------------------*/
/*----------------------------------------------------------------------------*/
t_vector		reflect_ray(t_vector ray, t_vector norm);
void			find_hit_distance(t_figure **obj, t_equition dot);
double			caps_intersection(t_vector pos, t_vector ray, t_vector norm, \
					t_vector center);
void			set_hit_normal(t_figure **obj, t_vector ray);
void			clear_scene(t_scene **scene);
void			error_exit(int condition, char *err);

#endif
