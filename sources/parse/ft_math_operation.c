/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:52:17 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/10 18:36:14 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	ft_is_within_range(double value, double lower_bound, double upper_bound)
{
	return (value >= lower_bound - EPSILON && value <= upper_bound + EPSILON);
}

bool	ft_is_within_range_weak(double value, \
	double lower_bound, double upper_bound)
{
	return (value >= lower_bound && value <= upper_bound);
}

bool	ft_is_near_equal(double num, double num2)
{
	return (fabs(num - num2) < EPSILON);
}

bool	ft_is_in_range_int(int num, int min, int max)
{
	return (num >= min && num <= max);
}
