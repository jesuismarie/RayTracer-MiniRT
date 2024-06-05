/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:00:50 by mnazarya          #+#    #+#             */
/*   Updated: 2023/01/22 14:00:50 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_f(const char *s)
{
	int	c;

	c = 0;
	while (*s++)
		c++;
	return (c);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putnbr_u(n / 10);
		count += ft_putchar((n % 10) + '0');
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n *= -1;
		count += write(1, "-", 1);
	}
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
		count += ft_putchar((n % 10) + '0');
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}

int	ft_putstr(char *s)
{
	int	count;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	count = ft_strlen_f(s);
	write(1, s, count);
	return (count);
}
