/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_vector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 22:31:54 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/10 18:53:52 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	ft_validate_vector(t_token *list, char **error)
{
	int		i;
	t_token	*tmp;

	if (!list)
		return (true);
	i = 0;
	tmp = list;
	while (tmp && i++ < 2)
	{
		if (tmp->next && tmp->next->type != P_SEMI)
			return (set_error(error, ft_format_error(__func__, "")));
		tmp = tmp->next;
		if (tmp)
		{
			if (tmp->next && tmp->next->type == P_SEMI)
				return (set_error(error, ft_format_error(__func__, "")));
			tmp = tmp->next;
		}
	}
	return (true);
}
