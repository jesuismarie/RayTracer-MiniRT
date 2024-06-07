/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:19:19 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/07 22:13:19 by gehovhan         ###   ########.fr       */
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
typedef struct s_tokenize_wrapper	t_tokenize_wrapper;
typedef struct s_tokenize_wrap		t_tokenize_wrap;

#include <stdbool.h>
#include <stdio.h>


#define EPSILON 1e-9


#define P_CAMERA_D "C"
#define P_LIGHT_D "L"
#define P_SPHERE_D "sp"
#define P_AMB_LIGHT_D "A"
#define P_PLANE_D "pl"
#define P_CYLINDER_D "cy"
#define P_CONE_D "co"



enum e_ptoken_type
{
	P_UNKNOWN = 77,
	P_CAMERA = 11,
	P_LIGHT = 55,
	P_AMB_LIGHT = 88,
	P_PLANE,
	P_CYLINDER,
	P_SPHERE,
	P_CONE,
	P_SEMI = 10
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


struct s_tokenize_wrapper
{
	t_list_token	*list;
	t_list_token	*space_list;
	t_token			*tmp;
	t_token			*head;
	char			*token;
	char			*tmp_token;
	t_ptoken_type	type;
};

struct s_tokenize_wrap
{
	size_t					index;
	char					*token_start;
	char					*next_token;
	t_ptoken_type			type;
	int						is_one_sym;
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
int				ft_tokenize_delim_helper(t_tokenize_wrap *wrap, t_ptoken_type *type);
char			*ft_tokenize_with_delims(char *str, t_ptoken_type *type);
void			ft_tokenize_delim_util(t_tokenize_wrap *wrap, t_ptoken_type *type);
int				ft_strcmp_std(char *s1, char *s2);
bool 			is_digit_float(char *str);
t_token 		*ft_jump(t_token *list, int step);

bool 			ft_validate_camera(t_list_token *list, char **error);
bool 			ft_validate_vector(t_token *list, char **error);
double			ft_atof(char *str);
t_list_token	*ft_tokenize(char *input);
// bool			is_in_range(double num, double min, double max);
// bool 		ft_pars_semi(t_list_token *list, char **error);
// bool 		ft_pars_args(t_list_token *list, char **error);
// int 			ft_semi_count(t_list_token *list);
// int 			ft_args_count(t_list_token *list, char **error);
// char    		*ft_format_error(const char *format, char *msg);



/**
 * PATH: ft_error.c
*/
void 			set_error(char **error, char *new_error);
char   		 	*ft_format_error(const char *format, char *msg);
/**
 * PATH: ft_create_camera.c
*/
bool			ft_create_camera(t_scene *scene, t_list_token	*list, char **error);
t_camera		ft_parse_camera(t_list_token *list);
bool			ft_validate_camera_args(t_camera camera, char **error);
bool			ft_validate_fov(int fov, char **error);
bool			ft_validate_dir(t_vector dir, char **error);

/**
 * PATH: ft_math_operation.c
*/
bool			ft_is_near_equal(double num, double num2);
bool			ft_is_within_range(double value, double lower_bound, double upper_bound);
bool			ft_is_in_range_int(int num, int min, int max);




#endif