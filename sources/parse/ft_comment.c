/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:23:49 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/13 00:17:51 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

char	*ft_ignore_comment(char *line)
{
	size_t	len;
	char	*no_comment;

	len = 0;
	while (line && ft_isspace(line[len]))
		++len;
	if (!line || !line[len])
	{
		free(line);
		return (ft_strdup(""));
	}
	while (line && line[len] && line[len] != '#')
		++len;
	no_comment = ft_substr(line, 0, len);
	free(line);
	return (no_comment);
}
