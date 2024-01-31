/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:56:18 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/31 20:51:51 by kyusulee         ###   ########.fr       */
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
