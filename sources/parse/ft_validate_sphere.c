/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_sphere.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <mnazarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:25:23 by gehovhan          #+#    #+#             */
/*   Updated: 2026/07/18 19:15:43 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static bool	ft_is_xpm_path(char *str)
{
	int	len;

	if (!str)
		return (false);
	len = ft_strlen(str);
	if (len < 5)
		return (false);
	if (ft_strcmp_std(str + len - 4, ".xpm") != 0)
		return (false);
	return (true);
}

static int	ft_sphere_args_count(t_list_token *list)
{
	int		size;
	t_token	*tmp;

	size = 0;
	tmp = list->head;
	tmp = tmp->next;
	while (tmp)
	{
		if (is_digit_float(tmp->token))
			size++;
		else if (tmp->type == P_SEMI)
			;
		else if (ft_is_xpm_path(tmp->token))
			;
		else
			return (-1);
		tmp = tmp->next;
	}
	return (size);
}

bool	ft_validate_sphere_util(t_token **tmp, t_list_token *list, char **error)
{
	int	count;

	*tmp = ft_jump(*tmp, 1);
	if (*tmp && (*tmp)->next && (*tmp)->next->type == P_SEMI)
		return (set_error(error, ft_format_error(__func__, "")));
	count = ft_sphere_args_count(list);
	if (count == SPHERE_MAX_ARGS + 1)
		*tmp = ft_jump(*tmp, 1);
	if (*tmp && (*tmp)->next && (*tmp)->next->type == P_SEMI)
		return (set_error(error, ft_format_error(__func__, "")));
	if (*tmp && (!ft_validate_vector((*tmp)->next, error)))
		return (set_error(error, ft_format_error(__func__, "")));
	*tmp = ft_jump(*tmp, 5);
	if (*tmp && (*tmp)->next && (*tmp)->next->type == P_SEMI)
		return (set_error(error, ft_format_error(__func__, "")));
	return (true);
}

bool	ft_validate_sphere(t_list_token *list, char **error)
{
	int		count;
	t_token	*tmp;

	tmp = list->head;
	if (!list->head || !list->head->next || \
		list->head->next->type == P_SEMI || \
		list->head->type != P_SPHERE || \
		!ft_pars_semi(list, error, SPHERE_MAX_COLONS))
		return (set_error(error, ft_format_error(__func__, "")));
	count = ft_sphere_args_count(list);
	if (count < SPHERE_MAX_ARGS || count > SPHERE_MAX_ARGS + 1)
		return (set_error(error, ft_format_error(__func__, "")));
	if (!ft_validate_vector(tmp->next, error))
		return (set_error(error, ft_format_error(__func__, "")));
	tmp = ft_jump(tmp->next, 4);
	if (tmp && tmp->next && tmp->next->type == P_SEMI)
		return (set_error(error, ft_format_error(__func__, "")));
	if (!ft_validate_sphere_util(&tmp, list, error))
		return (set_error(error, ft_format_error(__func__, "")));
	return (true);
}
