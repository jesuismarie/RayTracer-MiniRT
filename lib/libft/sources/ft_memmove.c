/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:00:40 by mnazarya          #+#    #+#             */
/*   Updated: 2023/01/22 14:00:40 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*d;
	char	*s;

	if (!dest && !src)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	if (dest > src)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(d + i) = *(s + i);
			i--;
		}
	}
	else
		while (n--)
			*d++ = *s++;
	return (dest);
}
