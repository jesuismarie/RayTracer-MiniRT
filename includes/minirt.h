/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:05:56 by mnazarya          #+#    #+#             */
/*   Updated: 2024/05/05 17:33:00 by mnazarya         ###   ########.fr       */
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

/*----------------------------------------------------------------------------*/
/*--------------------------------- GRAPHICS ---------------------------------*/
/*----------------------------------------------------------------------------*/
int				rgb_to_hex(t_color rgb);
t_color			calc_rgb_light(t_color col, double ratio);
t_color			multiply_rgbs(t_color a, t_color b);
t_color			add_rgb_light(t_color a, t_color b);
t_color			diffuse_light(t_light *light, t_intersect point);
void			update_pixel_color(t_scene *scene, t_figure *obj, int *color, \
					t_vector ray);
int				compute_shadow(t_scene *scene, t_vector ray, t_figure **obj, \
					t_light *light);
void			my_mlx_pixel_put(t_scene *scene, int x, int y, int color);
// unsigned int	my_mlx_pixel_get(t_scene *scene, int x, int y);

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
void			object_intersection(t_scene *scene, t_vector ray, int *color);

/*----------------------------------------------------------------------------*/
/*--------------------------------- CONTROL ----------------------------------*/
/*----------------------------------------------------------------------------*/
int				keys(int keycode, t_scene *scene);
int				close_win(t_scene *scene);

/*----------------------------------------------------------------------------*/
/*---------------------------------- UTILS -----------------------------------*/
/*----------------------------------------------------------------------------*/
void			clear_scene(t_scene **scene);
void			error_exit(int condition, char *err);

#endif
