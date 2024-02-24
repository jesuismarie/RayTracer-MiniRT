/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:51:27 by mnazarya          #+#    #+#             */
/*   Updated: 2024/02/22 18:39:39 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*read_str(int fd, char *s)
{
	char	*buf;
	int		n;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (1)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
		{
			free(buf);
			return (0);
		}
		buf[n] = '\0';
		if (n == 0)
			break ;
		s = ft_join_free(s, buf);
		if (ft_strchr(s, '\n'))
			break ;
	}
	free(buf);
	return (s);
}

char	*ft_find(char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	if (!str)
		return (0);
	i = -1;
	while (s[++i] && s[i] != '\n')
		str[i] = s[i];
	if (s[i] == '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_remainder(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\0')
	{
		free(s);
		return (0);
	}
	str = ft_calloc(ft_strlen(s) - i, sizeof(char));
	if (!str)
		return (0);
	j = 0;
	while (s[i] && s[++i])
		str[j++] = s[i];
	str[j] = '\0';
	free(s);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (0);
	str = read_str(fd, str);
	if (!str)
		return (0);
	line = ft_find(str);
	str = ft_remainder(str);
	if (line && !line[0])
	{
		free(line);
		return (0);
	}
	return (line);
}
