/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_method.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:55:37 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/05 23:49:53 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void    ft_init_token(t_token *node, int type, char *elem)
{
	node->type = type;
	node->token = elem;
	node->next = NULL;
	node->prev = NULL;
}

t_list_token	*ft_init_list(void)
{
	t_list_token	*list;

	list = (t_list_token *)malloc(sizeof(t_list_token));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return (list);
}

void	ft_push_back(t_list_token *list, int type, const char *token)
{
	t_token	*new;
	t_token	*tmp;

	if (!list)
		return ;
	new = (t_token *)malloc(sizeof(t_token));
	if (new == NULL)
		return ;
	ft_init_token(new, type, ft_strdup(token));
	if (list->head == NULL)
	{
		list->head = new;
		list->tail = new;
	}
	else
	{
		tmp = list->head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
		list->tail = new;
	}
	++list->size;
}

void	ft_print_list(t_token *list)
{
	t_token		*current;

	current = list;
	while (current)
	{
		printf("Type: %u, Token: %s\n", current->type, current->token);
		current = current->next;
	}
}

t_token *ft_jump(t_token *list, int step)
{
    if (!list)
        return (NULL);
    int i = 0;
    while (list && i < step)
    {
        list = list->next;
        ++i;
    }
    return (list);
}