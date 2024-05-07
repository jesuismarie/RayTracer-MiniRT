/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 22:37:26 by gehovhan          #+#    #+#             */
/*   Updated: 2024/05/07 23:12:14 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctype.h"
typedef struct s_token t_token;
typedef struct s_list_token t_list_token;
typedef enum e_figure_type t_figure_type;

typedef struct s_tokenize_wrapper	t_tokenize_wrapper;
typedef struct s_tokenize_wrap		t_tokenize_wrap;

enum e_figure_type
{
	SPHERE,
	CYLINDER,
	PLANE,
	CONE
};
struct s_tokenize_wrapper
{
	t_list_token	*list;
	t_list_token	*space_list;
	t_token			*tmp;
	t_token			*head;
	char			*token;
	char			*tmp_token;
	int				type;
};

struct s_tokenize_wrap
{
	size_t		index;
	char		*token_start;
	char		*next_token;
	int			type;
	int			is_one_sym;
};

struct s_list_token
{
	t_token	*head;
	t_token	*tail;
	size_t	size;
};


struct s_token
{
	t_figure_type		type;
	char				*token;
	t_token				*next;
	t_token				*prev;
};
