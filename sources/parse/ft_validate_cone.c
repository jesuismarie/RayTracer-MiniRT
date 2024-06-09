/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_cone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:25:23 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/10 01:06:08 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>


bool ft_validate_cone(t_list_token *list, char **error)
{
    t_token *tmp = list->head;

    if (!list->head || !list->head->next || list->head->next->type == P_SEMI || list->head->type != P_CONE || \
        !ft_pars_semi(list, error, CONE_MAX_COLONS))
        return (set_error(error, ft_format_error(__func__, "")));
    if (!(ft_pars_args(list, error, CONE_MAX_ARGS, CONE_MAX_ARGS + 1)))
        return (set_error(error, ft_format_error(__func__, "")));
    if (!ft_validate_vector(tmp->next, error))
        return (set_error(error, ft_format_error(__func__, "")));
    tmp = ft_jump(tmp->next, 4);
    if (!ft_validate_vector(tmp->next, error))
        return (set_error(error, ft_format_error(__func__, "")));
    tmp = ft_jump(tmp->next, 4);
    if (tmp && tmp->next && tmp->next->type == P_SEMI)
        return (set_error(error, ft_format_error(__func__, "")));
    tmp = ft_jump(tmp, 1);
    if (tmp && tmp->next && tmp->next->type == P_SEMI)
        return (set_error(error, ft_format_error(__func__, "")));
    tmp = ft_jump(tmp, 1);
    if (tmp && tmp->next && tmp->next->type == P_SEMI)
        return (set_error(error, ft_format_error(__func__, "")));
    if (!ft_skip_optional_arg(list, &tmp, error, CONE_MAX_ARGS + 1))
        return (set_error(error, ft_format_error(__func__, "")));
    if (tmp && tmp->next && tmp->next->type == P_SEMI)
        return (set_error(error, ft_format_error(__func__, "")));
    if (tmp && (!ft_validate_vector(tmp->next, error)))
        return (set_error(error, ft_format_error(__func__, "")));
    tmp = ft_jump(tmp, 5);
    if (tmp && tmp->next && tmp->next->type == P_SEMI)
        return (set_error(error, ft_format_error(__func__, "")));
    return (true);
}
