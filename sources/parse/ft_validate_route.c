/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_route.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:27:27 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/05 18:19:59 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool ft_create_camera(t_scene *list, t_list_token	*token, char **error)
{
    (void)list;
    (void)token;
    (void)error;
    return true;
}

bool ft_create_object(t_scene *scene, t_list_token	*list, char **error)
{
	t_ptoken_type ptype;

	ptype = ft_get_ptype(list->head->token);
	if (ptype == P_CAMERA)
		return (ft_create_camera(scene, list, error));
	// else if (ptype == P_AMB_LIGHT)
	// 	return (ft_create_light(scene, ptype, error));
	// else if (ptype == P_LIGHT)
	// 	return (ft_create_light(scene, ptype, error));
	// else if (ptype == PLANE)
	// 	return (ft_create_plane(scene, ptype, error));
	// else if (ptype == P_CYLINDER)
	// 	return (ft_create_cylinder(scene, ptype, error));
	// else if (ptype == P_SPHERE)
	// 	return (ft_create_sphere(scene, ptype, error));
	// else if (ptype == P_CONE)
	// 	return (ft_create_cone(scene, ptype, error));
    return true;
}

#include <stdio.h>
bool ft_validate_object(t_list_token *list, char **error)
{
	t_ptoken_type ptype;

	ptype = ft_get_ptype(list->head->token);
	if (ptype == P_CAMERA)
		return (ft_validate_camera(list, error));
	// else if (ptype == P_AMB_LIGHT)
	// 	return (ft_validate_amb_light(ptype, error));
	// else if (ptype == P_LIGHT)
	// 	return (ft_validate_light(ptype, error));
	// else if (ptype == PLANE)
	// 	return (ft_validate_plane(ptype, error));
	// else if (ptype == P_CYLINDER)
	// 	return (ft_validate_cylinder(ptype, error));
	// else if (ptype == P_SPHERE)
	// 	return (ft_validate_sphere(ptype, error));
	// else if (ptype == P_CONE)
	// 	return (ft_validate_cone(ptype, error));
    return true;
}