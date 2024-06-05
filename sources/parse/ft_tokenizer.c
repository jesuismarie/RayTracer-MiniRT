/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:15:30 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/05 21:12:30 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	ft_tokenize_space_helper(t_tokenize_space_helper *wrapper)
{
	while (wrapper->token_start[wrapper->index])
	{
		if (ft_isspace(wrapper->token_start[wrapper->index]))
		{
			wrapper->token_start[wrapper->index] = '\0';
			++wrapper->index;
			while (wrapper->token_start[wrapper->index] && \
					ft_isspace(wrapper->token_start[wrapper->index]))
				++wrapper->index;
			if (!wrapper->token_start[wrapper->index])
				wrapper->next_token = NULL;
			else
				wrapper->next_token = wrapper->token_start + wrapper->index;
			return (1);
		}
		++wrapper->index;
	}
	return (0);
}

char	*ft_tokenize_with_space(char *expr)
{
	t_tokenize_space_helper	wrapper;
	static char		*next_token;

	if (expr)
		next_token = expr;
	if (!next_token)
		return (NULL);
	wrapper.index = 0;
	wrapper.next_token = next_token;
	wrapper.token_start = next_token;
	if (ft_tokenize_space_helper(&wrapper))
	{
		next_token = wrapper.next_token;
		return (wrapper.token_start);
	}
	next_token = NULL;
	return (wrapper.token_start);
}

t_list_token	*ft_tokenize_space(char *input)
{
	t_ptoken_type	type;
	char			*token;
	t_list_token	*list;

	list = ft_init_list();
	type = P_UNKNOWN;
	token = ft_tokenize_with_space(input);
	while (token != NULL)
	{
		ft_push_back(list, type, token);
		token = ft_tokenize_with_space(NULL);
	}
	return (list);
}


void	ft_tokenize_helper(t_tokenize_wrapper *wrapper)
{
	wrapper->token = ft_tokenize_with_delims(wrapper->head->token, &wrapper->type);
	while (wrapper->token)
	{
		if (wrapper->type == P_SEMI)
		{
			if (*wrapper->token)
				ft_push_back(wrapper->list, P_UNKNOWN, wrapper->token);
			wrapper->tmp_token = ft_strdup(",");
			ft_push_back(wrapper->list, P_SEMI, wrapper->tmp_token);
			free(wrapper->tmp_token);
		}
		else if (*wrapper->token)
			ft_push_back(wrapper->list, P_UNKNOWN, wrapper->token);
		wrapper->token = ft_tokenize_with_delims(NULL, &wrapper->type);
	}
}

t_list_token	*ft_tokenize(char *input)
{
	t_tokenize_wrapper	wrapper;

	wrapper.type = 0;
	wrapper.list = ft_init_list();
	wrapper.space_list = ft_tokenize_space(input);
	wrapper.head = wrapper.space_list->head;
	while (wrapper.head)
	{
		wrapper.tmp = wrapper.head->next;
		ft_tokenize_helper(&wrapper);
		free(wrapper.head->token);
		free(wrapper.head);
		wrapper.head = wrapper.tmp;
	}
	free(wrapper.space_list);
	if (wrapper.list->head) {
		wrapper.list->head->type = ft_get_ptype(wrapper.list->head->token);
	}
	return (wrapper.list);
}
