/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:13:37 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/09 18:53:29 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

// figures []

bool ft_parse_object(t_scene *scene, t_list_token	*list, char **error) 
{
	// printf("sssss\n");
	// t_ptoken_type ptype;

	if (!ft_validate_object(list, error))
		return (set_error(error, ft_format_error(__func__, "888")));
	if (!ft_create_object(scene, list, error))
		return (set_error(error, ft_format_error(__func__, "222")));
	// ptype = ft_get_ptype(list->head->token);
	// t_figure *last_obj = ft_get_last_obj(scene->figure);

	// else if (ptype == P_LIGHT)
	// 	return (ft_create_light(scene, list, error));
	// else if (ptype == PLANE)
	// 	scene->figure = ft_push_back_obj(scene->figure, new_figure(scene->figure, ptype))
	// else if (ptype == P_CYLINDER)
	// 	scene->figure = ft_push_back_obj(scene->figure, new_figure(, ptype))
	// else if (ptype == P_SPHERE)
	// 	scene->figure = ft_push_back_obj(scene->figure, new_figure(, ptype))
	// else if (ptype == P_CONE)
	// 	scene->figure = ft_push_back_obj(scene->figure, new_figure(, ptype))
	
	
	return (true);
}

char *ft_parse(t_scene *scene, char **argv)
{
	(void)scene;
	int				fd;
	char			*line;
	t_list_token	*list;
	char 			*error;

	error = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return ft_strdup("error fd");
	line = NULL;
	while (ft_getline(fd, &line) > 0)
	{
		if (!line)
			return ft_strdup("false");
		line = ft_ignore_comment(line);
		if (line && !line[0])
			continue ;
		list = ft_tokenize(line);
		ft_print_list(list->head);

		if (ft_parse_object(scene, list, &error))
			break ;
	}
	return error;
}