/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize_cleanup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:25:17 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/12 19:25:40 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	ft_free_list(t_list_token *list)
{
	t_token	*tmp;
	t_token	*next;

	if (list == NULL)
		return ;
	if (list->head == NULL)
	{
		free(list);
		return ;
	}
	tmp = list->head;
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp->token);
		free(tmp);
		tmp = next;
	}
	list->head = NULL;
	list->size = 0;
	free(list);
}