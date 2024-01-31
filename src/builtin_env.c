/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:49:49 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/31 20:13:55 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <stdio.h>

void	builtin_env(t_dict *env_dict)
{
	t_pair	*tmp;

	if (!env_dict)
		exit_handler(1, PROGRAM_NAME, "dict is NULL: builtin_env().");
	tmp = env_dict->head;
	while (tmp)
	{
		printf("%s=%s\n", tmp->key, tmp->val);
		tmp = tmp->next;
	}
}

void	builtin_export(t_dict *env_dict, t_exe_lst *exes)
{
	t_exe_node	*tmp;
	char		*key;
	char		*val;
	int			i;

	tmp = exes->head->next;
	while (tmp)
	{
		i = 0;
		while (tmp->word[i] != '=')
			i++;
		key = ft_substr(tmp->word, 0, i);
		++i;
		val = ft_substr(tmp->word, i, ft_strlen(tmp->word) - i);
		dict_new_back(env_dict, key, val);
		tmp = tmp->next;
	}
}

void	builtin_unset(t_dict *env_dict, t_exe_lst *exes)
{
	t_exe_node	*tmp;

	tmp = exes->head->next;
	while (tmp)
	{
		del_pair_in_dict(env_dict, tmp->word);
		tmp = tmp->next;
	}
}
