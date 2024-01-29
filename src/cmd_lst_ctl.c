/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_ctl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:56:34 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/29 14:36:18 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_cmd_lst	*new_cmd_lst(void)
{
	t_cmd_lst	*lst;

	lst = nullguard(malloc(sizeof(*lst)), PROGRAM_NAME, "in new_cmd_lst");
	lst->head = NULL;
	lst->tail = NULL;
	lst->size = 0;
	return (lst);
}

void	cmd_lst_new_node_back(t_cmd_lst *cmds)
{

}

void	free_cmd_lst()
{

}
