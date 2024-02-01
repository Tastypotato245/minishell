/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:34:45 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/01 20:46:30 by kyusulee         ###   ########.fr       */
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
void		dictionary_size_check(t_dict *dict);
t_dict		*new_dictionary(void);
void		dict_new_back(t_dict *dict, char *key, char *val);
void		free_dict(t_dict *dict);
void		print_dict(t_dict *dict);

// dict_ctl2.c
void		free_pair(t_pair *pair);
t_pair		*find_pair_in_dict(t_dict *dict, char *key);
t_pair		*find_pre_pair_in_dict(t_dict *dict, char *key);
char		*find_val_in_dict(t_dict *dict, char *key);
void		del_pair_in_dict(t_dict *dict, char *key);

// dict_env.c
void		dict_modi_val_or_new_in_sort(t_dict *dict, char *key, char *val);
t_dict		*to_dict(char **envp);
char		**to_2darr(t_dict *env_dict);

#endif
