/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:13:37 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/12 23:19:21 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

bool	ft_parse_object(t_scene *scene, t_list_token *list, char **error)
{
	if (!ft_validate_object(list, error))
		return (set_error(error, ft_format_error(__func__, "")));
	if (!ft_create_object(scene, list, error))
		return (set_error(error, ft_format_error(__func__, "")));
	return (true);
}

bool	ft_execute(t_scene *scene, char *line, char **error)
{
	t_list_token	*list;
	char			*msg;

	msg = NULL;
	list = ft_tokenize(line);
	if (!ft_parse_object(scene, list, error))
	{
		msg = ft_strjoin(__func__, ": ");
		set_error(error, ft_format_error("Error", msg));
		free(msg);
		ft_free_list(list);
		return (false);
	}
	ft_free_list(list);
	return (true);
}

int	open_file(char *path, char **error)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		set_error(error, ft_strdup("error fd"));
	return (fd);
}

char	*ft_parse(t_scene *scene, char **argv)
{
	int		fd;
	char	*line;
	char	*error;

	error = NULL;
	fd = open_file(argv[1], &error);
	line = NULL;
	while (ft_getline(fd, &line) > 0)
	{
		if (!line)
			return (NULL);
		line = ft_ignore_comment(line);
		if (line && !line[0])
		{
			free(line);
			continue ;
		}
		if (!ft_execute(scene, line, &error))
		{
			free(line);
			break ;
		}
		free(line);
	}
	return (close(fd), error);
}
