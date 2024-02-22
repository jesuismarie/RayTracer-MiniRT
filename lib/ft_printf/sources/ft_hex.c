/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:18:23 by mnazarya          #+#    #+#             */
/*   Updated: 2024/02/22 17:14:14 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned long long n, short x)
{
	int	count;

	count = 0;
	if (x)
	{
		if (n < 16)
			count += ft_putchar("0123456789abcdef"[n % 16]);
		else
		{
			count += ft_hex(n / 16, x);
			count += ft_putchar("0123456789abcdef"[n % 16]);
		}
	}
	else
	{
		if (n < 16)
			count += ft_putchar("0123456789ABCDEF"[n % 16]);
		else
		{
			count += ft_hex(n / 16, x);
			count += ft_putchar("0123456789ABCDEF"[n % 16]);
		}	
	}
	return (count);
}

int	ft_ptr(unsigned long long n)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	count += ft_hex(n, 1);
	return (count);
}
