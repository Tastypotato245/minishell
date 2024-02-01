/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:14:33 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/01 20:31:40 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>

int	builtin_unset(t_dict *env, t_exe_lst *exes)
{
	t_exe_node	*tmp;

	tmp = exes->head->next;
	while (tmp)
	{
		del_pair_in_dict(env, tmp->word);
		tmp = tmp->next;
	}
	return (0);
}
