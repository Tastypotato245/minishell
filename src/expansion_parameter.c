/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_parameter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:39:17 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/04 16:39:19 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expansion.h>

void	parameter_expansion(char *word, t_dict *env)
{
	(void)word;
	(void)env;

	t_pair	*tmp;

	if (!env)
		exit_handler(1, PROGRAM_NAME, "dict is NULL: builtin_env().");
	tmp = env->head;
	while (tmp)
	{
		if (tmp->val != NULL)
			printf("%s=%s\n", tmp->key, tmp->val);
		tmp = tmp->next;
	}
}
