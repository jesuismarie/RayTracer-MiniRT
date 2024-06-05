/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:25:23 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/06 02:06:38 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>


void set_error(char **error, char *new_error)
{
    if (!error)
        return ;
    // if (*error)
    //     free(*error);
    char *str;

    str = NULL;
    if (new_error)
        str = ft_strdup(new_error);
    str = ft_gnl_strjoin(new_error, *error);
    if (*error)
    {
        free(*error);
        *error = NULL;
    }
    *error = str;
}

char    *ft_format_error(const char *format, char *msg)
{
    char    *res = 0;

    res = ft_gnl_strjoin(res, format);
    if (*res) 
        res = ft_gnl_strjoin(res, ": ");
    res = ft_gnl_strjoin(res, msg);
    return res;
}


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

bool is_in_range(double num) {
    return (num >= -1.0 && num <= 1.0);
}

bool ft_range_camera(t_token *list, char **error)
{
    t_token *tmp;
    int     i;

    if (!list)
        return (true);
    i = 0;
    tmp = list;
    while (tmp && i++ < 5)
    {
        if (tmp->type != P_SEMI)
        {
            double coord = ft_atof(tmp->token);
            printf("tok: %s\n", tmp->token);
            if (!is_in_range(coord))
            {
                set_error(error, ft_format_error(__func__, "ssss"));
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
