/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:01:12 by mnazarya          #+#    #+#             */
/*   Updated: 2023/01/22 14:01:12 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	free_malloc(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	str = NULL;
	return (1);
}

static int	word_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static char	**fill_str(char **store, char const *str, char c)
{
	size_t		len;
	size_t		i;
	char const	*st;

	i = 0;
	while (*str)
	{
		if (*str != c)
		{
			len = 0;
			while (*str && *str != c)
			{
				len++;
				str++;
			}
			st = str - len;
			store[i] = ft_substr(st, 0, len);
			if (!store[i++])
				return (0);
		}
		else
			str++;
	}
	store[i] = 0;
	return (store);
}

char	**ft_split(char const *s, char c)
{
	char	**splited_str;
	size_t	len;

	if (!s)
		return (0);
	len = word_count(s, c);
	splited_str = malloc(sizeof(char *) * (len + 1));
	if (!splited_str)
		return (0);
	splited_str = fill_str(splited_str, s, c);
	if (!splited_str && free_malloc(splited_str))
		return (0);
	return (splited_str);
}
