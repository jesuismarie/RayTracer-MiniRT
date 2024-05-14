/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:15:30 by gehovhan          #+#    #+#             */
/*   Updated: 2024/05/14 21:19:46 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	ft_ignore_quots(char *str, char quot, size_t i)
{
	if (str && str[i])
	{
		++i;
		while (str[i] && str[i] != quot)
			++i;
	}
	return (i);
}

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
	if (wrapper.token_start[wrapper.index] == '\"' || \
		wrapper.token_start[wrapper.index] == '\'')
	{
		wrapper.index = ft_ignore_quots(wrapper.token_start, \
						wrapper.token_start[wrapper.index], 0);
	}
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
