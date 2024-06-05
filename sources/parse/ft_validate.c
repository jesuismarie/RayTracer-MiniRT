/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:25:23 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/05 18:12:34 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void set_error(char **error, char *new_error)
{
    if (error)
        free(error);
    
    *error = ft_strdup(new_error);
}

char    *ft_format_error(const char *format, char *msg)
{
    char    *res;

    res = ft_strdup("Error: ");

    res = ft_gnl_strjoin(res, format);
    res = ft_gnl_strjoin(res, ": ");
    res = ft_gnl_strjoin(res, msg);
    return res;
}

bool ft_validate_camera(t_list_token *list, char **error)
{
    printf("aaaa\n");
    if (list->size < 4)
    {
        set_error(error, ft_format_error(__func__, " : Camera should have minimum 4 arguments."));
        return false;
    }
    return true;
}