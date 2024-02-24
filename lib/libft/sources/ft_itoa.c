/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:58:07 by mnazarya          #+#    #+#             */
/*   Updated: 2023/01/22 13:58:07 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	nbr_count(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (len + 1);
	if (n < 0)
	{
		len += 1;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*nbr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = nbr_count(n);
	nbr = (char *)malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (0);
	if (n == 0)
		nbr[0] = '0';
	if (n < 0)
	{
		nbr[0] = '-';
		n *= -1;
	}
	nbr[len] = '\0';
	while (n > 0)
	{
		nbr[--len] = n % 10 + '0';
		n /= 10;
	}
	return (nbr);
}
