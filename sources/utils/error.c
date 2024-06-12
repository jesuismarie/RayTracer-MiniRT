/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:44:12 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/12 20:15:44 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	error_exit(int condition, char *err)
{
	if (condition)
	{
		ft_printf("%s\n", err);
		exit(1);
	}
}

void	error_exit_allocated(int condition, char *err)
{
	if (condition)
	{
		ft_printf("%s\n", err);
		free(err);
		exit(1);
	}
}
