/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_plane.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:25:23 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/12 23:51:39 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool	ft_skip_optional_arg(t_list_token *list, \
	t_token **start, char **error, int max_ops_arg)
{
	int	count;

	count = ft_args_count(list, error);
	if (count == -1)
		return (set_error(error, ft_format_error(__func__, "")));
	if (count == max_ops_arg)
		*start = ft_jump(*start, 1);
	return (true);
}

bool	ft_validate_plane_util(t_token **tmp, t_list_token *list, char **error)
{
	*tmp = ft_jump((*tmp)->next, 4);
	if (!ft_skip_optional_arg(list, tmp, error, PLANE_MAX_ARGS + 1))
		return (set_error(error, ft_format_error(__func__, "")));
	if (*tmp && (*tmp)->next && (*tmp)->next->type == P_SEMI)
		return (set_error(error, ft_format_error(__func__, "")));
	if (*tmp && (!ft_validate_vector((*tmp)->next, error)))
		return (set_error(error, ft_format_error(__func__, "")));
	*tmp = ft_jump(*tmp, 5);
	if (*tmp && (*tmp)->next && (*tmp)->next->type == P_SEMI)
		return (set_error(error, ft_format_error(__func__, "")));
	return (true);
}

bool	ft_validate_plane(t_list_token *list, char **error)
{
	t_token	*tmp;

	tmp = list->head;
	if (!list->head || !list->head->next || \
		list->head->next->type == P_SEMI || \
		list->head->type != P_PLANE || \
		!ft_pars_semi(list, error, PLANE_MAX_COLONS))
		return (set_error(error, ft_format_error(__func__, "")));
	if (!(ft_pars_args(list, error, PLANE_MAX_ARGS, PLANE_MAX_ARGS + 1)))
		return (set_error(error, ft_format_error(__func__, "")));
	if (!ft_validate_vector(tmp->next, error))
		return (set_error(error, ft_format_error(__func__, "")));
	tmp = ft_jump(tmp->next, 4);
	if (tmp && tmp->next && tmp->next->type == P_SEMI)
		return (set_error(error, ft_format_error(__func__, "")));
	if (tmp && (!ft_validate_vector(tmp->next, error)))
		return (set_error(error, ft_format_error(__func__, "")));
	if (!ft_validate_plane_util(&tmp, list, error))
		return (set_error(error, ft_format_error(__func__, "")));
	return (true);
}
