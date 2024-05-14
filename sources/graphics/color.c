/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:39:17 by mnazarya          #+#    #+#             */
/*   Updated: 2024/05/14 16:58:50 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_color	new_color(int r, int g, int b, int t)
{
	t_color	col;

	col.r = r;
	col.g = g;
	col.b = b;
	col.t = t;
	return (col);
}
