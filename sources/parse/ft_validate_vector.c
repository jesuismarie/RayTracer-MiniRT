/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_vector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 22:31:54 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/07 22:43:50 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool ft_validate_vector(t_token *list, char **error)
{
    t_token *tmp;
    int     i;

    if (!list)
        return (true);
    i = 0;
    tmp = list;
    while (tmp && i++ < 2)
    {
        if (tmp->next && tmp->next->type != P_SEMI)
        {
            set_error(error, ft_format_error(__func__, ""));
            return (false);
        }
        tmp = tmp->next;
        if (tmp)
        {
            if (tmp->next && tmp->next->type == P_SEMI)
            {
                set_error(error, ft_format_error(__func__, ""));
                return (false);
            }
            tmp = tmp->next;
        }
    }
    return (true);
}