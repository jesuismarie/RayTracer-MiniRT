/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:13:37 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/10 23:53:05 by gehovhan         ###   ########.fr       */
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

/**
 * 
 * TODO: cleanup the list
*/
bool	ft_execute(t_scene *scene, char *line, char **error)
{
	t_list_token	*list;
	char			*msg;

	msg = NULL;
	list = ft_tokenize(line);
	ft_print_list(list->head);
	if (!ft_parse_object(scene, list, error))
	{
		msg = ft_strjoin(__func__, ": ");
		set_error(error, ft_format_error("Error", msg));
		free(msg);
		return (false);
	}
	return (true);
}

char	*ft_parse(t_scene *scene, char **argv)
{
	int				fd;
	char			*line;
	char			*error;

	error = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_strdup("error fd"));
	line = NULL;
	while (ft_getline(fd, &line) > 0)
	{
		if (!line)
			return (ft_strdup("false"));
		line = ft_ignore_comment(line);
		if (line && !line[0])
			continue ;
		if (!ft_execute(scene, line, &error))
			break ;
	}
	return (error);
}
