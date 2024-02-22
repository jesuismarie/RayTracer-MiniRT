/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:57:12 by mnazarya          #+#    #+#             */
/*   Updated: 2023/01/22 13:57:12 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	size_t			i;

	if (nmemb >= 2147483424 || size >= 2147483424)
		return (0);
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (0);
	i = 0;
	while (i < nmemb * size)
	{
		*(char *)(ptr + i) = 0;
		i++;
	}
	return ((void *)ptr);
}
