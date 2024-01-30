/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_ctl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:56:34 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/30 19:23:28 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

// for debug
static void	cmd_lst_size_check(t_cmd_lst *cmds)
{
	t_cmd_node	*tmp;	
	int			cnt;

	if (!cmds)
		exit_handler(1, PROGRAM_NAME, "cmd_lst is NULL: cmd_lst_size_check().");
	cnt = 0;
	tmp = cmds->head;
	while (tmp)
	{
		++cnt;
		tmp = tmp->next;
	}
	if (cnt != cmds->size)
		exit_handler(1, PROGRAM_NAME, "size not match: cmd_lst_size_check().");
	return ;
}

t_cmd_lst	*new_cmd_lst(void)
{
	t_cmd_lst	*cmds;

	cmds = null_guard(malloc(sizeof(*cmds)), PROGRAM_NAME, "new_cmd_lst().");
	cmds->head = NULL;
	cmds->tail = NULL;
	cmds->size = 0;
	return (cmds);
}

void	cmd_lst_new_back(t_cmd_lst *cmds, t_exe_lst *exes, t_rd_lst *rds)
{
	t_cmd_node	*new;

	if (!cmds)
		exit_handler(1, PROGRAM_NAME, "cmd_lst is NULL: cmd_lst_new_back().");
	if (!exes)
		exit_handler(1, PROGRAM_NAME, "exe_lst is NULL: cmd_lst_new_back().");
	if (!rds)
		exit_handler(1, PROGRAM_NAME, "rd_lst is NULL: cmd_lst_new_back().");
	new = null_guard(malloc(sizeof(*new)), PROGRAM_NAME, "cmd_lst_new_back().");
	new->exes = exes;
	new->rds = rds;
	new->next = NULL;
	if (!cmds->head)
	{
		cmds->head = new;
		cmds->tail = new;
		cmds->size = 1;
	}
	else
	{
		cmds->tail->next = new;
		cmds->tail = new;
		cmds->size += 1;
	}
	return ;
}
/* 
	if (!cmds->head)
		cmds->head = new;
	else
		cmds->tail->next = new;
	cmds->tail = new;
	cmds->size += 1;
*/

void	free_cmd_lst(t_cmd_lst *cmds)
{
	t_cmd_node	*tmp;	

	if (!cmds)
		exit_handler(1, PROGRAM_NAME, "cmd_lst is NULL: free_cmd_lst().");
	cmd_lst_size_check(cmds);
	while (cmds->head)
	{
		tmp = cmds->head;
		cmds->head = cmds->head->next;
		free_exe_lst(tmp->exes);
		tmp->exes = NULL;
		free_rd_lst(tmp->rds);
		tmp->rds = NULL;
		free(tmp);
	}
	free(cmds);
	cmds = NULL;
}

void	print_cmd_lst(t_cmd_lst *cmds)
{
	t_cmd_node	*tmp;	
	int			cnt;

	if (!cmds)
		exit_handler(1, PROGRAM_NAME, "cmd_lst is NULL: print_cmd_lst().");
	cnt = 0;
	tmp = cmds->head;
	while (tmp)
	{
		printf(" 🍔 cmd[%d]: ", cnt);
		print_exe_lst(tmp->exes);
		print_rd_lst(tmp->rds);
		printf("| 🍔\n");
		tmp = tmp->next;
		++cnt;
	}
	return ;
}
