/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:34:45 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/31 16:48:37 by kyusulee         ###   ########.fr       */
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

// dict_env_ctl.c
t_dict		*new_dictionary(void);
void		dict_new_back(t_dict *dict, char *key, char *val);
void		free_dict(t_dict *dict);
void		print_dict(t_dict *dict);

// dict_env_ctl2.c
void		free_pair(t_pair *pair);
t_pair		*find_pair_in_dict(t_dict *dict, char *key);
t_pair		*find_pre_pair_in_dict(t_dict *dict, char *key);
char		*get_val_in_dict(t_dict *dict, char *key);
void		del_pair_in_dict(t_dict *dict, char *key);

#endif
