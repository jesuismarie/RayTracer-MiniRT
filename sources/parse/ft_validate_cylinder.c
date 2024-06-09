/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_cylinder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:25:23 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/10 00:25:47 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>


bool ft_validate_cylinder(t_list_token *list, char **error)
{
    t_token *tmp = list->head;

    if (!list->head || !list->head->next || list->head->next->type == P_SEMI || list->head->type != P_CYLINDER || \
        !ft_pars_semi(list, error, CYLINDER_MAX_COLONS))
        return (set_error(error, ft_format_error(__func__, "1")));
    if (!(ft_pars_args(list, error, CYLINDER_MAX_ARGS, CYLINDER_MAX_ARGS + 1)))
        return (set_error(error, ft_format_error(__func__, "2")));
    if (!ft_validate_vector(tmp->next, error))
        return (set_error(error, ft_format_error(__func__, "3")));
    tmp = ft_jump(tmp->next, 4);
    if (!ft_validate_vector(tmp->next, error))
        return (set_error(error, ft_format_error(__func__, "3")));
    tmp = ft_jump(tmp->next, 4);
    if (tmp && tmp->next && tmp->next->type == P_SEMI)
        return (set_error(error, ft_format_error(__func__, "4")));
    tmp = ft_jump(tmp, 1);
    if (tmp && tmp->next && tmp->next->type == P_SEMI)
        return (set_error(error, ft_format_error(__func__, "1111")));
    tmp = ft_jump(tmp, 1);
    if (tmp && tmp->next && tmp->next->type == P_SEMI)
        return (set_error(error, ft_format_error(__func__, "1111")));
    if (!ft_skip_optional_arg(list, &tmp, error, CYLINDER_MAX_ARGS + 1))
        return (set_error(error, ft_format_error(__func__, "6")));
    if (tmp && tmp->next && tmp->next->type == P_SEMI)
        return (set_error(error, ft_format_error(__func__, "7")));
    if (tmp && (!ft_validate_vector(tmp->next, error)))
        return (set_error(error, ft_format_error(__func__, "8")));
    tmp = ft_jump(tmp, 5);
    if (tmp && tmp->next && tmp->next->type == P_SEMI)
        return (set_error(error, ft_format_error(__func__, "9")));
    return (true);
}
