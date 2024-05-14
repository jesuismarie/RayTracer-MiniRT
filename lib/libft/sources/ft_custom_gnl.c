/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_custom_gnl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:28:37 by gehovhan          #+#    #+#             */
/*   Updated: 2024/05/14 20:28:50 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*gnl_get_line(char *buffer)
{
	char	*line;
	int		index;

	index = 0;
	while (buffer && buffer[index] && buffer[index] != '\n')
		++index;
	if (!buffer || !(line = malloc((index + 1))))
		return (NULL);
	index = 0;
	while (buffer && buffer[index] && buffer[index] != '\n')
	{
		line[index] = buffer[index];
		++index;
	}
	line[index] = '\0';
	return (line);
}

char	*gnl_get_buffer(char *buffer)
{
	char	*change;
	size_t	size;
	int		index;
	int		c_index;

	index = 0;
	if (!buffer)
		return (NULL);
	while (buffer[index] && buffer[index] != '\n')
		++index;
	if (!buffer[index])
	{
		free(buffer);
		return (NULL);
	}
	size = ft_gnl_strlen(buffer) - index;
	if (!(change = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	++index;
	c_index = 0;
	while (buffer[index])
		change[c_index++] = buffer[index++];
	change[c_index] = '\0';
	free(buffer);
	return (change);
}

int		ft_getline(int fd, char **line)
{
	int				read_return;
	char			*buffer;
	static	char	*fd_buffer[1024] = {0};

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((read_return = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[read_return] = '\0';
		fd_buffer[fd] = ft_gnl_strjoin(fd_buffer[fd], buffer);
		if (ft_gnl_strchr(fd_buffer[fd], '\n') || ft_gnl_strchr(fd_buffer[fd], '\0'))
			break ;
	}
	free(buffer);
	if (read_return < 0)
		return (-1);
	*line = gnl_get_line(fd_buffer[fd]);
	fd_buffer[fd] = gnl_get_buffer(fd_buffer[fd]);
	if (!read_return && !*line)
	{
		free(fd_buffer[fd]);
		return (0);
	}
	return (1);
}
