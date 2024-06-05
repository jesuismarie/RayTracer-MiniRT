/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:13:37 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/05 18:18:58 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>




	// P_UNKNOWN,
	// P_CAMERA,
	// P_LIGHT,
	// P_AMB_LIGHT,
	// P_PLANE,
	// P_CYLINDER,
	// P_SPHERE,
	// P_CONE
bool ft_parse_object(t_scene *scene, t_list_token	*list, char **error) {
	
	if (ft_validate_object(list, error))
		ft_create_object(scene, list, error);
	return true;
}

bool ft_create_objects(t_scene *scene, t_list_token	*list, char **error)
{
	return ft_parse_object(scene, list, error);
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
		list = ft_tokenize_space(line);
		ft_print_list(list->head);
		if (ft_create_objects(scene, list, &error))
			break ;
	}
	return error;
}