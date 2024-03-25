/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:44:12 by mnazarya          #+#    #+#             */
/*   Updated: 2024/03/25 18:48:28 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

int	print_err(char *err)
{
	ft_printf("%s\n", err);
	return (0);
}

void	error_exit(int condition, char *err)
{
	if (condition)
	{
		ft_printf("%s\n", err);
		exit(1);
	}
}
