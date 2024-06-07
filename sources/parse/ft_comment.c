/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:23:49 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/07 22:43:16 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

char *ft_ignore_comment(char *line)
{
	size_t len;

	len = 0;
	while (line && line[len] && line[len] != '#')
		++len;
	return ft_substr(line, 0, len);
}