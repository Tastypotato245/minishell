/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:49:49 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/04 16:15:47 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <stdio.h>

int	env_naming_check(char *key)
{
	int	i;
	int	len;

	if (key == NULL)
		return (0);
	len = ft_strlen(key);
	
	if (!(ft_isalpha(key[0]) || key[0] == '_'))
		return (0);
	i = 0;
	while (++i < len)
	{
		if (!(ft_isalpha(key[i]) || ft_isdigit(key[i]) || key[i] == '_'))
			return (0);
	}
	return (1);
}

int	builtin_env(t_dict *env, t_exe_lst *exes)
{
	t_pair	*tmp;

	if (exes->size != 1)
		return (return_handler(1, BTIN_ENV, NULL, "Invalid arguments."));
	if (!env)
		exit_handler(1, PROGRAM_NAME, "dict is NULL: builtin_env().");
	tmp = env->head;
	while (tmp)
	{
		if (tmp->val != NULL)
			printf("%s=%s\n", tmp->key, tmp->val);
		tmp = tmp->next;
	}
	return (0);
}
