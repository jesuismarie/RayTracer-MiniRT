/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:58:11 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/12 19:34:31 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# ifdef __linux__
#  define ESC	65307
#  define LEFT	65361
#  define RIGHT	65363
#  define DOWN	65364
#  define UP	65362
#  define KEY_A	97
#  define KEY_S	115
#  define KEY_D	100
#  define KEY_W	119
#  define KEY_C	99
#  define KEY_T	116
#  define KEY_B	98
# else
#  define ESC	53
#  define LEFT	123
#  define RIGHT	124
#  define DOWN	125
#  define UP	126
#  define KEY_A	0
#  define KEY_S	1
#  define KEY_D	2
#  define KEY_W	13
#  define KEY_C	8
#  define KEY_T	17
#  define KEY_B	11
# endif

# define WIDTH		1000
# define HEIGHT		700

# define MALLOC_ERR	"Can't allocate memory"

#endif
