/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:25:23 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/07 22:43:53 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool ft_range_camera(t_token *list, char **error)
{
    int     i;
    double  coord;
    t_token *tmp;

    if (!list)
        return (true);
    i = 0;
    tmp = list;
    while (tmp && i++ < 5)
    {
        if (tmp->type != P_SEMI)
        {
            coord = ft_atof(tmp->token);
            if (!ft_is_within_range(coord, -1.0, 1.0))
            {
                set_error(error, ft_format_error(__func__, ""));
                return (false);
            }
        }
        tmp = tmp->next;
    }
    return (true);
}

bool ft_validate_camera(t_list_token *list, char **error)
{
    t_token *tmp = list->head;

    if (!list->head || !list->head->next || list->head->next->type == P_SEMI || list->head->type != P_CAMERA || !ft_pars_args(list, error) || !ft_pars_semi(list, error))
    {
        set_error(error, ft_format_error(__func__, ""));
        return (false);
    }
    if (!ft_validate_vector(tmp->next, error))
    {
        set_error(error, ft_format_error(__func__, ""));
        return (false);
    }
    tmp = ft_jump(tmp->next, 4);
    if (tmp && tmp->next && tmp->next->type == P_SEMI)
    {
        set_error(error, ft_format_error(__func__, ""));
        return (false);
    }
    if (tmp && (!ft_validate_vector(tmp->next, error) || !ft_range_camera(tmp->next, error)))
    {
        set_error(error, ft_format_error(__func__, ""));
        return (false);
    }

    tmp = ft_jump(tmp->next, 4);
    if (tmp && tmp->next && tmp->next->type == P_SEMI)
    {
        set_error(error, ft_format_error(__func__, ""));
        return (false);
    }

    tmp = ft_jump(tmp, 1);
    if (tmp && tmp->next && tmp->next->type == P_SEMI)
    {
        set_error(error, ft_format_error(__func__, ""));
        return (false);
    }
    return (true);
}
