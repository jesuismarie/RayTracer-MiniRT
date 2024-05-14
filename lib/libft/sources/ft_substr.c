/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:02:06 by mnazarya          #+#    #+#             */
/*   Updated: 2023/01/22 14:02:06 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	n;

	if (!s)
		return (0);
	n = ft_strlen(s);
	if ((size_t)start >= n)
		return (ft_strdup(""));
	if (len > n - (size_t)start)
		len = n - (size_t)start;
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (s[i] && i < len)
	{
		str[i] = s[(size_t)start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}


// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t			s_len;
// 	size_t			over_len;
// 	unsigned int	index;
// 	char			*str;

// 	if (!s)
// 		return (NULL);
// 	s_len = ft_strlen(s);
// 	over_len = ft_strlen(s + start);
// 	index = 0;
// 	if (len > over_len)
// 		len = over_len;
// 	if (!(str = malloc((len + 1) * sizeof(char))))
// 		return (NULL);
// 	while (index < len && start + index < (unsigned int)s_len)
// 	{
// 		str[index] = *(s + start + index);
// 		++index;
// 	}
// 	str[index] = '\0';
// 	return (str);
// }