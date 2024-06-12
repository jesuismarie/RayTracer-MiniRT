/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:13:37 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/12 20:23:06 by mnazarya         ###   ########.fr       */
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

char	*ft_parse(t_scene *, char **argv)
{
	int				fd;
	char			*line;
	char			*error;

	error = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_strdup("error fd"));
	if (!ft_strrchr(argv[1], '.') \
		|| ft_strcmp_std(ft_strrchr(argv[1], '.'), ".rt"))
		return (ft_strdup("Wrong file type"));
	line = NULL;
	while (ft_getline(fd, &line) > 0)
	{
		if (!line)
			return (ft_strdup("false"));
		// line = ft_ignore_comment(line);
		// if (line && !line[0])
		// {
		// 	free(line);	
		// 	continue ;
		// }
		// if (!ft_execute(scene, line, &error))
		// {
		// 	free(line);
		// 	break ;
		// }
		// free(line);
		free(line);
	}
	// if (line)
	// 	free(line);
	return (error);
}
