/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:58:48 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/07 22:41:36 by gehovhan         ###   ########.fr       */
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

double ft_atof(char *str)
{
    int 	whole_part = 0;
    double 	decimal_part = 0.0;
    int 	neg = 1;
    bool 	has_decimal = false;

	whole_part = 0;
	decimal_part = 0.0;
	neg = 1;
	has_decimal = false;
    if (*str == '-') {
        neg = -1;
        str++;
    } 
	else if (*str == '+')
        str++;
    while (ft_isdigit(*str))
        whole_part = whole_part * 10 + (*(str++) - '0');
    if (*str == '.')
	{
        has_decimal = true;
        str++;
        double divisor = 10.0;
        while (ft_isdigit(*str)) {
            decimal_part += (*str - '0') / divisor;
            divisor *= 10.0;
            str++;
        }
    }
    return ((double)(whole_part + decimal_part) * neg);
}

bool is_digit_float(char *str)
{
    bool has_digits = false;
    bool has_decimal_point = false;

	if (str && *str == '\0')
		return (false);
    if (*str == '+' || *str == '-')
    	str++;
    while (str && *str != '\0')
	{
        if (ft_isdigit(*str))
            has_digits = true;
        else if (*str == '.') {
            if (has_decimal_point)
                return (false);
            has_decimal_point = true;
        } else
            return (false);
        str++;
    }
    return (has_digits);
}