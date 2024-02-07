/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_ctl4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:03:03 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/07 14:53:37 by kyusulee         ###   ########.fr       */
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
		if (dict_modi_val_or_new_in_sort(env_dict, key, val))
			free(key);
		i++;
	}
	return (env_dict);
}

static char	**envp_malloc(t_dict *env_dict)
{
	t_pair	*tmp;
	char	**envp;
	int		arrlen;

	arrlen = 0;
	tmp = env_dict->head;
	while (tmp)
	{
		if (tmp->val != NULL)
			++arrlen;
		tmp = tmp->next;
	}
	envp = null_guard(malloc(sizeof(char *) * (arrlen + 1)), \
			PROGRAM_NAME, "get_env_arrlen().");
	return (envp);
}

char	**to_2darr(t_dict *env_dict)
{
	char	**envp;
	t_pair	*tmp;
	int		i;
	int		len;

	envp = envp_malloc(env_dict);
	tmp = env_dict->head;
	i = 0;
	while (tmp)
	{
		if (tmp->val != NULL && ft_strncmp(tmp->key, "?", 2) != 0)
		{
			len = ft_strlen(tmp->key) + 1 + ft_strlen(tmp->val);
			envp[i] = null_guard(malloc(len + 1), PROGRAM_NAME, "to_2darr().");
			ft_strlcpy(envp[i], tmp->key, len);
			ft_strlcat(envp[i], "=", len + 1);
			ft_strlcat(envp[i], tmp->val, len + 1);
			++i;
		}
		tmp = tmp->next;
	}
	envp[i] = NULL;
	return (envp);
}
