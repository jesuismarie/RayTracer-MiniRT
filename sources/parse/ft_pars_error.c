/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <mnazarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:54:13 by gehovhan          #+#    #+#             */
/*   Updated: 2026/05/13 17:43:18 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool	set_error(char **error, char *new_error)
{
	char	*str;

	if (!error)
		return (true);
	str = ft_gnl_strjoin(new_error, *error);
	if (*error)
	{
		free(*error);
		*error = NULL;
	}
	*error = str;
	return (false);
}

char	*ft_format_error(const char *format, const char *msg)
{
	char	*res;

	res = 0;
	res = ft_gnl_strjoin(res, format);
	if (*res)
		res = ft_gnl_strjoin(res, ": ");
	res = ft_gnl_strjoin(res, msg);
	return (res);
}
