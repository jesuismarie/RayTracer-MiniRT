/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokeniz_delim.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:26:33 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/10 18:39:08 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	ft_tokenize_delim_helper(t_tokenize_wrap *wrap, t_ptoken_type *type)
{
	char	delim;

	delim = ',';
	wrap->is_one_sym = 0;
	while (wrap->token_start[wrap->index])
	{
		if (delim == wrap->token_start[wrap->index])
		{
			wrap->is_one_sym = 1;
			*type = P_SEMI;
			wrap->token_start[wrap->index] = '\0';
			wrap->next_token = wrap->token_start + wrap->index + 1;
			return (1);
		}
		else
			*type = 0;
		++wrap->index;
	}
	return (0);
}

char	*ft_tokenize_with_delims(char *str, t_ptoken_type *type)
{
	static char		*next_token;
	t_tokenize_wrap	wrapper;

	if (str)
		next_token = str;
	if (!next_token)
		return (NULL);
	wrapper.token_start = next_token;
	wrapper.next_token = next_token;
	wrapper.index = 0;
	*type = P_UNKNOWN;
	if (ft_tokenize_delim_helper(&wrapper, type))
	{
		next_token = wrapper.next_token;
		return (wrapper.token_start);
	}
	next_token = NULL;
	return (wrapper.token_start);
}
