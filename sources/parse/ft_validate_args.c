/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 22:36:34 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/07 22:43:42 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int ft_args_count(t_list_token *list, char **error)
{
    int size;
    t_token *tmp;

    size = 0;
    tmp = list->head;
    tmp = tmp->next;
    while (tmp)
    {
        if (is_digit_float(tmp->token))
            size++;
        else if (tmp->type != P_SEMI)
        {
            set_error(error, ft_format_error(__func__, ""));
            return (-1);
        }
        tmp = tmp->next;
    }
    return (size);
}

int ft_semi_count(t_list_token *list)
{
    int size;
    t_token *tmp;

    tmp = list->head;
    tmp = tmp->next;
    size = 0;
    while (tmp)
    {
        if (tmp->type == P_SEMI)
            size++;
        tmp = tmp->next;
    }
    return (size);
}


bool ft_pars_args(t_list_token *list, char **error)
{
	int max_args;

    max_args = 7;
    int count = ft_args_count(list, error);
    printf("%d\n", count);
    if (count == -1)
    {
        set_error(error, ft_format_error(__func__, ""));
        return (false);
    }
    if (count != 7)
    {
        set_error(error, ft_format_error(__func__, ""));
        return (false);
    }
    return (true);
}

bool ft_pars_semi(t_list_token *list, char **error)
{
    int max_semi;
    int count_semi;

    max_semi = 4;
    count_semi = ft_semi_count(list);
    if (count_semi != 4)
    {
        set_error(error, ft_format_error(__func__, ""));
        return (false);
    }
    return (true);
}