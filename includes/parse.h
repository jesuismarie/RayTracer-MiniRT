/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:19:19 by gehovhan          #+#    #+#             */
/*   Updated: 2024/06/10 01:24:18 by gehovhan         ###   ########.fr       */
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
typedef enum s_check_type			t_check_type;

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


#define CAMERA_MAX_ARGS 7
#define AMB_MAX_ARGS 4
#define LIGHT_MAX_ARGS 7

#define CAMERA_MAX_COLONS 4
#define AMB_MAX_COLONS 2
#define LIGHT_MAX_COLONS 4
#define PLANE_MAX_COLONS 6
#define SPHERE_MAX_COLONS 4
#define CYLINDER_MAX_COLONS 6
#define CONE_MAX_COLONS 6

#define PLANE_MAX_ARGS 9
#define SPHERE_MAX_ARGS 7
#define CYLINDER_MAX_ARGS 11
#define CONE_MAX_ARGS 11
// #define PLANE_MAX_ARGS_OPS 10



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

enum s_check_type
{
	FLOAT,
	INT
};

/**
 * PATH: ft_pars_error.c
*/
bool 			set_error(char **error, char *new_error);
char			*ft_format_error(const char *format, const char *msg);

/**
 * PATH: ft_comment.c
*/
char 			*ft_ignore_comment(char *line);

/**
 * PATH: ft_create_camera.c
*/
bool			ft_create_camera(t_scene *scene, t_list_token	*list, char **error);
bool			ft_parse_camera(t_list_token *list, t_camera *camera, char **error);
bool			ft_validate_camera_args(t_camera camera, char **error);
bool			ft_validate_fov(int fov, char **error);
bool			ft_validate_dir(t_vector dir, char **error);

/**
 * ft_validate_amb_light.c
*/
bool ft_validate_amb_light(t_list_token	*list, char **error);
bool ft_create_amb_light(t_scene *scene, t_list_token	*list, char **error);
bool ft_validate_plane(t_list_token *list, char **error);
















/**
 * PATH: ft_math_operation.c
*/
bool			ft_is_near_equal(double num, double num2);
bool			ft_is_within_range(double value, double lower_bound, double upper_bound);
bool			ft_is_in_range_int(int num, int min, int max);
bool			ft_is_within_range_weak(double value, double lower_bound, double upper_bound);


/**
 * PATH: ft_list_method.c
*/
t_list_token	*ft_init_list(void);
void	        ft_push_back(t_list_token *list, int type, const char *token);
void	        ft_init_token(t_token *node, int type, char *elem);
t_token 		*ft_jump(t_token *list, int step);
void			ft_print_list(t_token *list);

/**
 * PATH: ft_ptype.c
*/
t_ptoken_type	ft_get_ptype(char *type);


/**
 * PATH: ft_tokenize.c
*/
t_list_token	*ft_tokenize(char *input);
void			ft_tokenize_helper(t_tokenize_wrapper *wrapper);
t_list_token	*ft_tokenize_space(char *input);
char			*ft_tokenize_with_space(char *expr);
int				ft_tokenize_space_helper(t_tokenize_space_helper *wrapper);

/**
 * PATH: ft_tokeniz_delim.c
*/
int				ft_tokenize_delim_helper(t_tokenize_wrap *wrap, t_ptoken_type *type);
char			*ft_tokenize_with_delims(char *str, t_ptoken_type *type);


/**
 * ft_parse.c
*/
char 			*ft_parse(t_scene *scene, char **argv);
bool			ft_parse_object(t_scene *scene, t_list_token	*list, char **error);


/**
 * PATH: ft_validate.c
*/
bool			ft_validate_camera(t_list_token *list, char **error);
bool			ft_range_camera(t_token *list, char **error);

/**
 * ft_validate_route.c
*/
bool			ft_validate_object(t_list_token *list, char **error);
bool			ft_create_object(t_scene *scene, t_list_token	*list, char **error);

/**
 * PATH: ft_validate_vector.c
*/
bool			ft_validate_vector(t_token *list, char **error);

/**
 * PATH: ft_validate_args.c
*/
bool			ft_pars_semi(t_list_token *list, char **error, int max_colon_count);
bool			ft_pars_args(t_list_token *list, char **error, int min_count, int max_count);
int				ft_semi_count(t_list_token *list);
int				ft_args_count(t_list_token *list, char **error);

/**
 * PATH: ft_pars_util.c
*/
double			ft_atof(char *str);
int				ft_strcmp_std(char *s1, char *s2);
bool			is_digit_float(char *str);
bool			ft_is_integer(const char *str);



bool ft_validate_color(t_color color, char **error);
bool ft_validate_light(t_list_token *list, char **error);
bool ft_create_light(t_scene *scene, t_list_token *list, char **error);
bool ft_validate_color_args(t_token *start, t_token *end, char **error);

t_color ft_parse_color(t_token *start);
t_vector ft_parse_pos(t_token *start);
bool ft_parse_dir(t_token *start, t_vector *vec, char **error);


t_figure	*ft_push_back_obj(t_figure *start, t_figure *obj);
t_figure 	*new_figure(void *obj, t_figure_type type);
t_figure	*ft_get_last_obj(t_figure* start);
bool 		ft_create_plane(t_scene *scene, t_list_token	*list, char **error);
bool 		ft_parse_plane(t_list_token *list, t_plane *plane, char **error);
bool 		ft_validate_plane_args(t_plane plane, char **error);
bool		ft_skip_optional_arg(t_list_token *list, t_token **start, char **error, int max_ops_arg);

bool ft_validate_sphere(t_list_token *list, char **error);
bool ft_create_sphere(t_scene *scene, t_list_token	*list, char **error);

bool ft_validate_cylinder(t_list_token *list, char **error);
bool ft_create_cylinder(t_scene *scene, t_list_token	*list, char **error);

bool ft_validate_cone(t_list_token *list, char **error);
bool ft_create_cone(t_scene *scene, t_list_token	*list, char **error);
// bool ft_parse_optional_arg(t_plane *plane, t_list_token *list, t_token **start, char **error);
#endif