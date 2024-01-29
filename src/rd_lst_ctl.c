/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd_lst_ctl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:00:40 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/29 18:14:30 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// for debug
static void	rd_lst_size_check(t_rd_lst *rds)
{
	t_rd_node	*tmp;	
	int			cnt;

	if (!rds)
		exit_handler(1, PROGRAM_NAME, "rd_lst is NULL: rd_lst_size_check().");
	cnt = 0;
	tmp = rds->head;
	while (tmp)
	{
		++cnt;
		tmp = tmp->next;
	}
	if (cnt != rds->size)
		exit_handler(1, PROGRAM_NAME, "size not match: rd_lst_size_check().");
	return ;
}

t_rd_lst	*new_rd_lst(void)
{
	t_rd_lst	*rds;

	rds = null_guard(malloc(sizeof(*rds)), PROGRAM_NAME, "new_rd_lst().");
	rds->head = NULL;
	rds->tail = NULL;
	rds->size = 0;
	return (rds);
}

void	rd_lst_new_back(t_rd_lst *rds, t_rd_type rd_type, char *file)
{
	t_rd_node	*new;

	if (!rds)
		exit_handler(1, PROGRAM_NAME, "rd_lst is NULL: rd_lst_new_back().");
	if (!file)
		exit_handler(1, PROGRAM_NAME, "file is NULL: rd_lst_new_back().");
	new = null_guard(malloc(sizeof(*new)), PROGRAM_NAME, "rd_lst_new_back().");
	new->rd_type = rd_type;
	new->file = file;
	new->next = NULL;
	if (!rds->head)
	{
		rds->head = new;
		rds->tail = new;
		rds->size = 1;
	}
	else
	{
		rds->tail->next = new;
		rds->tail = new;
		rds->size += 1;
	}
	return ;
}
/*
	if (!rds->head)
		rds->head = new;
	else
		rds->tail->next = new;
	rds->tail = new;
	rds->size += 1;
*/

void	free_rd_lst(t_rd_lst *rds)
{
	t_rd_node	*tmp;	

	if (!rds)
		exit_handler(1, PROGRAM_NAME, "rd_lst is NULL: free_rd_lst().");
	rd_lst_size_check(rds);
	while (rds->head)
	{
		tmp = rds->head;
		rds->head = rds->head->next;
		free(tmp->file);
		tmp->file = NULL;
		free(tmp);
	}
	free(rds);
	rds = NULL;
}

void	print_rd_lst(t_rd_lst *rds)
{
	t_rd_node	*tmp;	

	if (!rds)
		exit_handler(1, PROGRAM_NAME, "rd_lst is NULL: print_rd_lst().");
	tmp = rds->head;
	printf("rds: ");
	while (tmp)
	{
		printf("[ rd_type: %d ] { file: %s } ", tmp->rd_type, tmp->file);
		tmp = tmp->next;
	}
	return ;
}
