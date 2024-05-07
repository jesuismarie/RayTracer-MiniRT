/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 22:36:22 by gehovhan          #+#    #+#             */
/*   Updated: 2024/05/07 23:13:54 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <parsing.h>



int	ft_tokenize_space_helper(t_tokenize_wrap *wrapper)
{
	while (wrapper->token_start[wrapper->index])
	{
		if (ft_isspace(wrapper->token_start[wrapper->index]))
		{
			wrapper->token_start[wrapper->index] = '\0';
			++wrapper->index;
			while (wrapper->token_start[wrapper->index] && \
					ft_isspace(wrapper->token_start[wrapper->index]))
				++wrapper->index;
			if (!wrapper->token_start[wrapper->index])
				wrapper->next_token = NULL;
			else
				wrapper->next_token = wrapper->token_start + wrapper->index;
			return (1);
		}
		++wrapper->index;
	}
	return (0);
}

char	*ft_tokenize_with_space(char *expr)
{
	t_tokenize_wrap	wrapper;
	static char		*next_token;

	if (expr)
		next_token = expr;
	if (!next_token)
		return (NULL);
	wrapper.index = 0;
	wrapper.next_token = next_token;
	wrapper.token_start = next_token;
	if (wrapper.token_start[wrapper.index] == '\"' || \
		wrapper.token_start[wrapper.index] == '\'')
	{
		wrapper.index = ft_ignore_quots(wrapper.token_start, \
						wrapper.token_start[wrapper.index], 0);
	}
	if (ft_tokenize_space_helper(&wrapper))
	{
		next_token = wrapper.next_token;
		return (wrapper.token_start);
	}
	next_token = NULL;
	return (wrapper.token_start);
}

t_list_token	*ft_tokenize_string_space(char *input)
{
	int				type;
	char			*token;
	t_list_token	*list;

	type = 0;
	list = ft_init_list();
	token = ft_tokenize_with_space(input);
	while (token != NULL)
	{
        
		ft_push_back(list, token);
		token = ft_tokenize_with_space(NULL);
	}
	return (list);
}


int ft_parsing(char *file_path)
{
    //TODO: check extension .rt
    int status = access(file_path, F_OK | R_OK);
    char* line;
    if (status)
        error_exit(status, "File doesnt exists");
    int fd = open(file_path, O_RDONLY);

    if (fd)
    {
        while (1)
        {
            line = get_next_line(fd);
            
            free(line);
        }
        
    }
    else
    {
        //err
    }

}