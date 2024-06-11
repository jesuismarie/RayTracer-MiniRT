/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:58:48 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/11 21:07:23 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	ft_strcmp_std(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] == s2[i])
	{
		if ((s1[i] == '\0') && (s2[i] == '\0'))
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

static void	check_dot(char *str, double *decimal_part)
{
	double	divisor;

	if (*str == '.')
	{
		str++;
		divisor = 10.0;
		while (ft_isdigit(*str))
		{
			*decimal_part += (*str - '0') / divisor;
			divisor *= 10.0;
			str++;
		}
	}
}

double	ft_atof(char *str)
{
	int		whole_part;
	int		neg;
	double	decimal_part;

	whole_part = 0;
	decimal_part = 0.0;
	neg = 1;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
		whole_part = whole_part * 10 + (*(str++) - '0');
	check_dot(str, &decimal_part);
	return (neg * (double)(whole_part + decimal_part));
}

bool	is_digit_float(char *str)
{
	bool	has_digits;
	bool	has_decimal_point;

	has_digits = false;
	has_decimal_point = false;
	if (str && *str == '\0')
		return (false);
	if (*str == '+' || *str == '-')
		str++;
	while (str && *str != '\0')
	{
		if (ft_isdigit(*str))
			has_digits = true;
		else if (*str == '.')
		{
			if (has_decimal_point)
				return (false);
			has_decimal_point = true;
		}
		else
			return (false);
		str++;
	}
	return (has_digits);
}

bool	ft_is_integer(const char *str)
{
	if (str && *str == '\0')
		return (false);
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}
