/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:01:58 by mnazarya          #+#    #+#             */
/*   Updated: 2023/01/22 14:01:58 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	b;

	b = (char)c;
	if (!s)
		return (0);
	i = ft_strlen((char *)s);
	while (i > 0)
	{
		if (s[i] == b)
			return ((char *)s + i);
		i--;
	}
	if (s[0] == b)
		return ((char *)s + i);
	return (0);
}
