/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:58:11 by mnazarya          #+#    #+#             */
/*   Updated: 2024/04/11 18:50:31 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# ifdef __linux__
#  define ESC 65307
#  define LEFT 65361
#  define RIGHT 65363
#  define DOWN 65364
#  define UP 65362
# else
#  define ESC 53
#  define LEFT 123
#  define RIGHT 124
#  define DOWN 125
#  define UP 126
# endif

# define WIDTH	800
# define HEIGHT	600

# define MALLOC_ERR	"Can't allocate memory"

#endif
