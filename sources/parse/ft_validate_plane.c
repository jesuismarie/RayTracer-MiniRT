/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_plane.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:25:23 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/09 20:53:00 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

// bool ft_range_dir(t_token *list, char **error)
// {
//     int     i;
//     double  coord;
//     t_token *tmp;

//     if (!list)
//         return (true);
//     i = 0;
//     tmp = list;
//     while (tmp && i++ < 5)
//     {
//         if (tmp->type != P_SEMI)
//         {
//             coord = ft_atof(tmp->token);
//             if (!ft_is_within_range(coord, -1.0, 1.0))
//                 return (set_error(error, ft_format_error(__func__, "")));
//         }
//         tmp = tmp->next;
//     }
//     return (true);
// }

bool ft_skip_optional_arg(t_list_token *list, t_token **start, char **error, int max_ops_arg)
{
    int count = ft_args_count(list, error);
    if (count == -1)
        return (set_error(error, ft_format_error(__func__, "")));
    if (count == max_ops_arg)
        *start = ft_jump(*start, 1);
    return (true);
}

bool ft_validate_plane(t_list_token *list, char **error)
{
    t_token *tmp = list->head;

    if (!list->head || !list->head->next || list->head->next->type == P_SEMI || list->head->type != P_PLANE || \
        !ft_pars_semi(list, error, PLANE_MAX_COLONS))
        return (set_error(error, ft_format_error(__func__, "1")));
    if (!(ft_pars_args(list, error, PLANE_MAX_ARGS, PLANE_MAX_ARGS + 1)))
        return (set_error(error, ft_format_error(__func__, "2")));
    if (!ft_validate_vector(tmp->next, error))
        return (set_error(error, ft_format_error(__func__, "3")));
    tmp = ft_jump(tmp->next, 4);
    if (tmp && tmp->next && tmp->next->type == P_SEMI)
        return (set_error(error, ft_format_error(__func__, "4")));
    if (tmp && (!ft_validate_vector(tmp->next, error)))
        return (set_error(error, ft_format_error(__func__, "5")));
    tmp = ft_jump(tmp->next, 4);
    if (!ft_skip_optional_arg(list, &tmp, error, PLANE_MAX_ARGS + 1))
        return (set_error(error, ft_format_error(__func__, "6")));
    // printf("%s\n", tmp->token);
    if (tmp && tmp->next && tmp->next->type == P_SEMI)
        return (set_error(error, ft_format_error(__func__, "7")));
    if (tmp && (!ft_validate_vector(tmp->next, error)))
        return (set_error(error, ft_format_error(__func__, "8")));
    tmp = ft_jump(tmp, 5);
    if (tmp && tmp->next && tmp->next->type == P_SEMI)
        return (set_error(error, ft_format_error(__func__, "9")));
    return (true);
}
