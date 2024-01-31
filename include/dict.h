/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:34:45 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/31 17:46:57 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# include <minishell.h>
# include <kyusulib.h>

typedef struct s_pair
{
	char			*key;
	char			*val;
	struct s_pair	*next;
}	t_pair;

typedef struct s_dict
{
	struct s_pair	*head;
	struct s_pair	*tail;
	int				size;
}	t_dict;

// dict_ctl1.c
t_dict		*new_dictionary(void);
void		dict_new_back(t_dict *dict, char *key, char *val);
void		free_dict(t_dict *dict);
void		print_dict(t_dict *dict);

// dict_ctl2.c
void		free_pair(t_pair *pair);
t_pair		*find_pair_in_dict(t_dict *dict, char *key);
t_pair		*find_pre_pair_in_dict(t_dict *dict, char *key);
char		*get_val_in_dict(t_dict *dict, char *key);
void		del_pair_in_dict(t_dict *dict, char *key);

// dict_env.c
t_dict		*to_dict(char **envp);
void		builtin_env(t_dict *env_dict);
void		builtin_export(t_dict *env_dict, char *line);
void		builtin_unset(t_dict *env_dict, char *key);

#endif
