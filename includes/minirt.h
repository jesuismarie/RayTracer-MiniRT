/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:05:56 by mnazarya          #+#    #+#             */
/*   Updated: 2024/04/22 20:31:00 by mnazarya         ###   ########.fr       */
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
void			img_init(char **argv, t_scene *scene);
t_camera		*new_camera(t_vector pos, t_vector dir, int fov);
t_light			*new_light(t_vector coord, t_color col, float brightness);
t_amb_light		*new_amb_light(t_color col, float ratio);
t_sphere		*new_sphere(t_vector center, float r);
t_cylinder		*new_cylinder(t_vector center, t_vector axis, float r, float h);

/*----------------------------------------------------------------------------*/
/*---------------------------------- VECTOR ----------------------------------*/
/*----------------------------------------------------------------------------*/
t_vector		new_vector(float x, float y, float z);
t_vector		vector_sub(t_vector vect1, t_vector vect2);
t_vector		vector_sum(t_vector vect1, t_vector vect2);
t_vector		vector_prod(t_vector vect, float n);
float			vector_len(t_vector vect);
void			normalize_vector(t_vector *vect);
float			vector_scalar_prod(t_vector v1, t_vector v2);

/*----------------------------------------------------------------------------*/
/*--------------------------------- GRAPHICS ---------------------------------*/
/*----------------------------------------------------------------------------*/
int				rgb_to_hex(t_color rgb);
t_color			calc_rgb_light(t_color col, float ratio);
t_color			multiply_rgbs(t_color a, t_color b);
t_color			add_rgb_light(t_color a, t_color b);
t_color			diffuse_light(t_light *light, t_intersect point);
void			update_pixel_color(t_scene *scene, t_figure *obj, int *color);
int				in_shadow(t_scene *scene, t_vector ray);
void			my_mlx_pixel_put(t_scene *scene, int x, int y, int color);
// unsigned int	my_mlx_pixel_get(t_scene *scene, int x, int y);

/*----------------------------------------------------------------------------*/
/*------------------------------- RAY TRACING --------------------------------*/
/*----------------------------------------------------------------------------*/
float			sphere_intersection(t_scene *scene, t_vector ray, \
					t_figure **obj);
float			cylinder_intersection(t_scene *scene, t_vector ray, \
					t_figure **obj);
void			object_intersection(t_scene *scene, t_vector ray, int *color);
t_vplane		*get_view_plane(t_scene *scene);
void			trace_ray(t_scene *scene);

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
