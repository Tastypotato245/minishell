/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:56:18 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/31 17:46:57 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dict.h>

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
		dict_new_back(env_dict, key, val);
		i++;
	}
	return (env_dict);
}

void	builtin_env(t_dict *env_dict)
{
	t_pair	*tmp;

	if (!dict)
		exit_handler(1, PROGRAM_NAME, "dict is NULL: print_dict().");
	tmp = dict->head;
	while (tmp)
	{
		printf("%s=%s\n", tmp->key, tmp->val);
		tmp = tmp->next;
	}
}

void		builtin_export(t_dict *env_dict, t_exe_lst *exes)
{

}

void		builtin_unset(t_dict *env_dict, t_exe_lst *exes)
{
	del_pair_in_dict(env_dict, key);
}
