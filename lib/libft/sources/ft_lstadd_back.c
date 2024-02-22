/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:58:40 by mnazarya          #+#    #+#             */
/*   Updated: 2023/01/22 13:58:40 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*n;

	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		n = ft_lstlast(*lst);
		n->next = new;
	}
}
