/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:15:57 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:15:57 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin_bonus.h>

int	unset_arg_check(char *word)
{
	int	i;
	int	len;

	len = ft_strlen(word);
	if (!(ft_isalpha(word[0]) || word[0] == '_'))
		return (return_handler(0, BTIN_UNSET, word, "not a valid identifier"));
	i = 1;
	while (i < len && word[i])
	{
		if (!(ft_isalpha(word[i]) || ft_isdigit(word[i]) || word[i] == '_'))
			return (return_handler(0, BTIN_UNSET, word, \
						"not a valid identifier"));
		++i;
	}
	return (1);
}

int	builtin_unset(t_dict *env, t_exe_lst *exes)
{
	t_exe_node	*tmp;
	int			check;

	check = 0;
	tmp = exes->head->next;
	while (tmp)
	{
		if (unset_arg_check(tmp->word))
			del_pair_in_dict(env, tmp->word);
		else
			check = 1;
		tmp = tmp->next;
	}
	return (check);
}
