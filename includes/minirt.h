/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:05:56 by mnazarya          #+#    #+#             */
/*   Updated: 2024/03/27 21:11:42 by mnazarya         ###   ########.fr       */
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
void		init_scene(t_scene **scene);
void		win_init(char **argv, t_scene **scene);
void		img_init(t_scene *scene);
t_camera	*new_camera(t_vector pos, t_vector dir, int fov);
t_amb_light	*new_amb_light(t_color col, float ratio);
t_sphere	*new_sphere(t_vector center, t_color col, float r, float spec);

/*----------------------------------------------------------------------------*/
/*---------------------------------- VECTOR ----------------------------------*/
/*----------------------------------------------------------------------------*/
t_vector	new_vector(float x, float y, float z);
t_vector	vector_sub(t_vector vect1, t_vector vect2);
t_vector	vector_sum(t_vector vect1, t_vector vect2);
t_vector	vector_prod(t_vector vect, float n);
float		vector_len(t_vector vect);
void		normalize_vector(t_vector *vect);
float		vector_scalar_prod(t_vector v1, t_vector v2);

/*----------------------------------------------------------------------------*/
/*--------------------------------- GRAPHICS ---------------------------------*/
/*----------------------------------------------------------------------------*/
int			rgb_to_hex(t_figure *obj);
void		my_mlx_pixel_put(t_scene *scene, int x, int y, int color);

/*----------------------------------------------------------------------------*/
/*------------------------------- RAY TRACING --------------------------------*/
/*----------------------------------------------------------------------------*/
float		sphere_intersection(t_scene *scene, t_vector ray, t_sphere *sphere);
void		object_intersection(t_scene *scene, t_vector ray, int *color);
t_vplane	*get_view_plane(t_scene *scene);
void		trace_ray(t_scene *scene);

/*----------------------------------------------------------------------------*/
/*--------------------------------- CONTROL ----------------------------------*/
/*----------------------------------------------------------------------------*/
int			keys(int keycode, t_scene *scene);
int			close_win(t_scene *scene);

/*----------------------------------------------------------------------------*/
/*---------------------------------- UTILS -----------------------------------*/
/*----------------------------------------------------------------------------*/
void		clear_scene(t_scene **scene);
int			print_err(char *err);
void		error_exit(int condition, char *err);

#endif
