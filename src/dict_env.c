/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:56:18 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/01 18:35:05 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dict.h>

static void	dict_add_pair_in_sort(t_dict *dict, t_pair *new)
{
	t_pair	*pre;
	int		new_key_len;

	new_key_len = ft_strlen(new->key);
	if (ft_strncmp(new->key, dict->head->key, new_key_len) <= 0)
	{
		new->next = dict->head;
		dict->head = new;
		dict->size += 1;
		return ;
	}
	pre = dict->head;
	while (pre->next)
	{
		if (ft_strncmp(new->key, pre->next->key, new_key_len) <= 0)
			break ;
		pre = pre->next;
	}
	new->next = pre->next;
	if (pre->next == NULL)
		dict->tail = new;
	pre->next = new;
	dict->size += 1;
}

static void	dict_new_in_sort(t_dict *dict, char *key, char *val)
{
	t_pair	*new;

	new = null_guard(malloc(sizeof(*new)), PROGRAM_NAME, "dict_new_in_sort().");
	new->key = key;
	new->val = val;
	new->next = NULL;
	if (!dict->head)
	{
		dict->head = new;
		dict->tail = new;
		dict->size = 1;
		return ;
	}
	dict_add_pair_in_sort(dict, new);
	return ;
}

void	dict_modi_val_or_new_in_sort(t_dict *dict, char *key, char *val)
{
	t_pair	*tmp;

	if (!dict)
		exit_handler(1, PROGRAM_NAME, "dict is NULL: dict_mv_nis().");
	if (!key || key[0] == '\0')
		exit_handler(1, PROGRAM_NAME, "key is NULL or empty: dict_mv_nis().");
	tmp = find_pair_in_dict(dict, key);
	if (tmp == NULL)
		dict_new_in_sort(dict, key, val);
	tmp->val = val;
}

t_dict	*to_dict(char **envp)
{
	t_dict	*env_dict;
	int		i;
	int		j;
	char	*key;
	char	*val;

	env_dict = new_dictionary();
	i = 0;
	while (envp && envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		key = ft_substr(envp[i], 0, j);
		++j;
		val = ft_substr(envp[i], j, ft_strlen(envp[i]) - j);
//		dict_modi_val_or_new_in_sort(env_dict, key, val);
		dict_new_back(env_dict, key, val);
		i++;
	}
	return (env_dict);
}

//printf("\tenvp[%d]: %s\n", i, envp[i]);
char	**to_2darr(t_dict *env_dict)
{
	char	**envp;
	t_pair	*tmp;
	int		i;
	int		len;

	if (!env_dict)
		exit_handler(1, PROGRAM_NAME, "dict is NULL: to_2darr().");
	envp = null_guard(malloc(sizeof(char *) * (env_dict->size + 1)), \
			PROGRAM_NAME, "to_2darr().");
	envp[env_dict->size] = NULL;
	tmp = env_dict->head;
	i = 0;
	len = 0;
	while (tmp)
	{
		len = ft_strlen(tmp->key) + 1 + ft_strlen(tmp->val);
		envp[i] = null_guard(malloc(len + 1), PROGRAM_NAME, "to_2darr().");
		ft_strlcpy(envp[i], tmp->key, len);
		ft_strlcat(envp[i], "=", len + 1);
		ft_strlcat(envp[i], tmp->val, len + 1);
		tmp = tmp->next;
		++i;
	}
	return (envp);
}
