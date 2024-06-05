/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:19:19 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/05 18:12:56 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

typedef struct s_node				t_node;
typedef struct s_token				t_token;
typedef struct s_list_token			t_list_token;
typedef enum   e_ptoken_type		t_ptoken_type;

typedef struct s_tokenize_wrapper	t_tokenize_wrapper;
typedef struct s_tokenize_space_helper		t_tokenize_space_helper;

#include <stdbool.h>
#include <stdio.h>

#define P_CAMERA_D "C"
#define P_LIGHT_D "L"
#define P_SPHERE_D "sp"
#define P_AMB_LIGHT_D "A"
#define P_PLANE_D "pl"
#define P_CYLINDER_D "cy"
#define P_CONE_D "co"

enum e_ptoken_type
{
	P_UNKNOWN,
	P_CAMERA,
	P_LIGHT,
	P_AMB_LIGHT,
	P_PLANE,
	P_CYLINDER,
	P_SPHERE,
	P_CONE
};

struct s_token
{
	t_ptoken_type		type;
	char				*token;
	t_token				*next;
	t_token				*prev;
};

struct s_list_token
{
	t_token	*head;
	t_token	*tail;
	size_t	size;
};

struct s_tokenize_space_helper
{
	size_t		index;
	char		*token_start;
	char		*next_token;
	int			type;
	int			is_one_sym;
};


t_list_token	*ft_tokenize_space(char *input);
t_ptoken_type	ft_get_ptype(char *type);
void	        ft_init_token(t_token *node, int type, char *elem);
t_list_token	*ft_init_list(void);
void	        ft_push_back(t_list_token *list, int type, const char *token);
double			file_atof(char **str);
char 			*ft_parse(t_scene *scene, char **argv);
void			ft_print_list(t_token *list);
char 			*ft_ignore_comment(char *line);
bool 			ft_create_object(t_scene *scene, t_list_token	*list, char **error);
bool 			ft_validate_object(t_list_token *list, char **error);
bool			ft_validate_camera(t_list_token *list, char **error);

bool			ft_create_camera(t_scene *list, t_list_token	*token, char **error);


#endif