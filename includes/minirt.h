/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:05:56 by mnazarya          #+#    #+#             */
/*   Updated: 2024/02/28 16:35:50 by mnazarya         ###   ########.fr       */
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

int			print_err(char *err);

int			keys(int keycode, t_scene *scene);
int			close_win(t_scene *scene);

t_vector	new_vector(float x, float y, float z);
t_vector	vector_sub(t_vector vect1, t_vector vect2);
t_vector	vector_sum(t_vector vect1, t_vector vect2);
t_vector	vector_prod(t_vector vect, float n);
float		vector_len(t_vector vect);
void		normalize_vector(t_vector vect);
float		vector_scalar_prod(t_vector v1, t_vector v2);

#endif