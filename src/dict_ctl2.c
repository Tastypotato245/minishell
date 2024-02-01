/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_ctl2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:54:05 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/31 19:19:37 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dict.h>

void	free_pair(t_pair *pair)
{
	free(pair->key);
	pair->key = NULL;
	free(pair->val);
	pair->val = NULL;
	pair->next = NULL;
	free(pair);
}

t_pair	*find_pair_in_dict(t_dict *dict, char *key)
{
	t_pair	*tmp;

	if (!dict)
		exit_handler(1, PROGRAM_NAME, "dict is NULL: find_pair_in_dict().");
	if (!key)
		exit_handler(1, PROGRAM_NAME, "key is NULL: find_pair_in_dict().");
	tmp = dict->head;
	while (tmp)
	{
		if (ft_strncmp(tmp->key, key, ft_strlen(tmp->key)) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_pair	*find_pre_pair_in_dict(t_dict *dict, char *key)
{
	t_pair	*tmp;

	tmp = dict->head;
	while (tmp->next)
	{
		if (ft_strncmp(tmp->next->key, key, ft_strlen(tmp->next->key)) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

char	*find_val_in_dict(t_dict *dict, char *key)
{
	t_pair	*tmp;

	tmp = find_pair_in_dict(dict, key);
	if (tmp == NULL)
		return (NULL);
	return (tmp->val);
}

void	del_pair_in_dict(t_dict *dict, char *key)
{
	t_pair	*tmp;
	t_pair	*pre;

	if (!dict)
		exit_handler(1, PROGRAM_NAME, "dict is NULL: get_val_in_dict().");
	if (!key)
		exit_handler(1, PROGRAM_NAME, "key is NULL: get_val_in_dict().");
	tmp = dict->head;
	if (tmp == NULL)
		return ;
	if (ft_strncmp(tmp->key, key, ft_strlen(tmp->key)) == 0)
	{
		dict->head = tmp->next;
		free_pair(tmp);
		return ;
	}
	pre = find_pre_pair_in_dict(dict, key);
	if (pre == NULL || pre->next == NULL)
		return ;
	tmp = pre->next;
	pre->next = tmp->next;
	if (tmp == dict->tail)
		dict->tail = pre;
	free_pair(tmp);
}