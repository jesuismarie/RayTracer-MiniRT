/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:21:43 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/08 16:21:55 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool ft_validate_color(t_color color, char **error)
{
    if (!ft_is_in_range_int(color.r, 0, 255) || !ft_is_in_range_int(color.g, 0, 255) || !ft_is_in_range_int(color.b, 0, 255))
        return (set_error(error, ft_format_error(__func__, "")));
    return true;
}

bool ft_validate_color_args(t_token *start, t_token *end, char **error)
{
    t_token *tmp = start;
    while (tmp != end)
    {
        if (tmp->type != P_SEMI && !ft_is_integer(tmp->token))
            return (set_error(error, ft_format_error(__func__, "")));
        tmp = ft_jump(tmp, 1);
    }
    return true;
}