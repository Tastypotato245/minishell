/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:49:49 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/01 20:35:18 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <stdio.h>

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
