/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:19:27 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:23:15 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_BONUS_H
# define DICT_BONUS_H

# include <minishell_bonus.h>
# include <kyusulib_bonus.h>

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

// dict_ctl3.c
int			dict_modi_val_or_new(t_dict *dict, char *key, char *val);

// dict_ctl4.c
t_dict		*to_dict(char **envp);
char		**to_2darr(t_dict *env_dict);

#endif
