/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_route.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:27:27 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/10 20:21:25 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool	ft_create_object(t_scene *scene, t_list_token	*list, char **error)
{
	t_ptoken_type	ptype;

	ptype = ft_get_ptype(list->head->token);
	if (ptype == P_CAMERA)
		return (ft_create_camera(scene, list, error));
	else if (ptype == P_AMB_LIGHT)
		return (ft_create_amb_light(scene, list, error));
	else if (ptype == P_LIGHT)
		return (ft_create_light(scene, list, error));
	else if (ptype == P_PLANE)
		return (ft_create_plane(scene, list, error));
	else if (ptype == P_CYLINDER)
		return (ft_create_cylinder(scene, list, error));
	else if (ptype == P_SPHERE)
		return (ft_create_sphere(scene, list, error));
	else if (ptype == P_CONE)
		return (ft_create_cone(scene, list, error));
	return (true);
}

bool	ft_validate_object(t_list_token *list, char **error)
{
	t_ptoken_type	ptype;

	ptype = ft_get_ptype(list->head->token);
	if (ptype == P_CAMERA)
		return (ft_validate_camera(list, error));
	else if (ptype == P_AMB_LIGHT)
		return (ft_validate_amb_light(list, error));
	else if (ptype == P_LIGHT)
		return (ft_validate_light(list, error));
	else if (ptype == P_PLANE)
		return (ft_validate_plane(list, error));
	else if (ptype == P_CYLINDER)
		return (ft_validate_cylinder(list, error));
	else if (ptype == P_SPHERE)
		return (ft_validate_sphere(list, error));
	else if (ptype == P_CONE)
		return (ft_validate_cone(list, error));
	else
		return (set_error(error, ft_format_error(__func__, "")));
	return (false);
}
