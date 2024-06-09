/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:23:20 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/09 20:31:09 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>



t_light ft_parse_light(t_list_token *list)
{
    t_light light;
    t_token *tmp;

    tmp = ft_jump(list->head, 1);
    // printf("hhhhhh %s\n", tmp->token);
    light.coordinate = ft_parse_pos(tmp);
    tmp = ft_jump(tmp, 4);
    light.brightness = ft_atof(tmp->token);
    tmp = ft_jump(tmp, 1);
    light.color = ft_parse_color(tmp);
    return light;
}

bool ft_create_light(t_scene *scene, t_list_token *list, char **error)
{
    t_light light;

    light = ft_parse_light(list);
    if (!ft_validate_color(light.color, error))
        return (set_error(error, ft_format_error(__func__, "1")));
    scene->light = new_light(light.coordinate, light.color, light.brightness);
    scene->figure = ft_push_back_obj(scene->figure, new_figure(new_light(light.coordinate, light.color, light.brightness), LIGHT));
    return false;
}

bool ft_validate_light(t_list_token *list, char **error)
{
    t_token *tmp;
    t_token *prev;
    double ratio;

    tmp = list->head;
    if (!list->head || !list->head->next || list->head->next->type == P_SEMI || list->head->type != P_LIGHT || \
    !ft_pars_args(list, error, LIGHT_MAX_ARGS, LIGHT_MAX_ARGS) || !ft_pars_semi(list, error, LIGHT_MAX_COLONS))
        return (set_error(error, ft_format_error(__func__, "1")));
    tmp = ft_jump(tmp, 1);
    if (!ft_validate_vector(tmp, error))
        return (set_error(error, ft_format_error(__func__, "2")));
     tmp = ft_jump(tmp->next, 4);
    if (tmp && tmp->next && tmp->next->type == P_SEMI)
        return (set_error(error, ft_format_error(__func__, "3")));
    ratio = ft_atof(tmp->token);
    if (!ft_is_within_range(ratio, 0.0, 1.0))
        return (set_error(error, ft_format_error(__func__, "4")));
    tmp = ft_jump(tmp, 1);
    if (!ft_validate_vector(tmp, error))
        return (set_error(error, ft_format_error(__func__, "5")));
    prev  = tmp;
    tmp = ft_jump(tmp, 5);
    if (!ft_validate_color_args(prev, tmp, error))
        return (set_error(error, ft_format_error(__func__, "6")));
    if (tmp && tmp->next && tmp->next->type == P_SEMI)
        return (set_error(error, ft_format_error(__func__, "5")));
    return (true);
}