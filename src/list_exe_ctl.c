/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_lst_ctl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:40:26 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/05 22:46:54 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

static void	exe_lst_size_check(t_exe_lst *exes)
{
	t_exe_node	*tmp;	
	int			cnt;

	if (!exes)
		exit_handler(1, PROGRAM_NAME, "exe_lst is NULL: exe_lst_size_check().");
	cnt = 0;
	tmp = exes->head;
	while (tmp)
	{
		++cnt;
		tmp = tmp->next;
	}
	if (cnt != exes->size)
		exit_handler(1, PROGRAM_NAME, "size not match: exe_lst_size_check().");
	return ;
}

t_exe_lst	*new_exe_lst(void)
{
	t_exe_lst	*exes;

	exes = null_guard(malloc(sizeof(*exes)), PROGRAM_NAME, "new_exe_lst().");
	exes->head = NULL;
	exes->tail = NULL;
	exes->size = 0;
	return (exes);
}

void	exe_lst_new_back(t_exe_lst *exes, char *word)
{
	t_exe_node	*new;

	if (!exes)
		exit_handler(1, PROGRAM_NAME, "exe_lst is NULL: exe_lst_new_back().");
	if (!word)
		exit_handler(1, PROGRAM_NAME, "word is NULL: exe_lst_new_back().");
	new = null_guard(malloc(sizeof(*new)), PROGRAM_NAME, "exe_lst_new_back().");
	new->word = word;
	new->next = NULL;
	if (!exes->head)
	{
		exes->head = new;
		exes->tail = new;
		exes->size = 1;
	}
	else
	{
		exes->tail->next = new;
		exes->tail = new;
		exes->size += 1;
	}
	return ;
}

void	free_exe_lst(t_exe_lst *exes)
{
	t_exe_node	*tmp;	

	if (!exes)
		exit_handler(1, PROGRAM_NAME, "exe_lst is NULL: free_exe_lst().");
	exe_lst_size_check(exes);
	while (exes->head)
	{
		tmp = exes->head;
		exes->head = exes->head->next;
		free(tmp->word);
		tmp->word = NULL;
		free(tmp);
	}
	free(exes);
	exes = NULL;
}

void	print_exe_lst(t_exe_lst *exes)
{
	t_exe_node	*tmp;	

	if (!exes)
		exit_handler(1, PROGRAM_NAME, "exe_lst is NULL: print_exe_lst().");
	tmp = exes->head;
	printf("exes: ");
	while (tmp)
	{
		printf("( %s ) ", tmp->word);
		tmp = tmp->next;
	}
	return ;
}
