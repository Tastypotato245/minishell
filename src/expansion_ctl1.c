/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_ctl1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:13:53 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/06 13:20:39 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expansion.h>
#include <stdlib.h>

static void	exes_append(t_exe_lst *dst_exes, t_exe_lst *src_exes, int mod)
{
	t_exe_node	*tmp;

	if (mod == 1)
	{
		tmp = src_exes->head;
		src_exes->head = src_exes->head->next;
		src_exes->size -= 1;
		free (tmp->word);
		free (tmp);
		if (src_exes->size == 0)
			src_exes->tail = NULL;
	}
	if (src_exes->size != 0)
	{
		if (dst_exes->size == 0)
			dst_exes->head = src_exes->head;
		else
			dst_exes->tail->next = src_exes->head;
		dst_exes->tail = src_exes->tail;
		dst_exes->size += src_exes->size;
	}
	free(src_exes);
}

static void	exes_quote_removal(t_exe_lst *exes)
{
	t_exe_node	*exe;
	char		*buf;

	exe = exes->head;
	while (exe)
	{
		buf = quote_removal(exe->word);
		free(exe->word);
		exe->word = buf;
		exe = exe->next;
	}
}

static t_exe_lst	*exes_expansion(t_exe_lst *exes, t_dict *env)
{
	t_exe_node	*exe;
	t_exe_lst	*tmp_exes;
	t_exe_lst	*final_exes;
	int			checker;

	checker = 0;
	final_exes = new_exe_lst();
	exe = exes->head;
	while (exe && !checker)
	{
		tmp_exes = filename_expansion(parameter_expansion(exe->word, env));
		exes_quote_removal(tmp_exes);
		exes_append(final_exes, tmp_exes, 0);
		if (ft_strncmp(final_exes->head->word, "export", 7) == 0)
			checker = 1;
		exe = exe->next;
	}
	if (checker)
	{
		exes_append(final_exes, exes, 1);
		return (final_exes);
	}
	free_exe_lst(exes);
	return (final_exes);
}

void	exes_export_expansion(t_exe_lst *exes, t_dict *env)
{
	t_exe_node	*exe;
	char		*tmp_str;

	exe = exes->head->next;
	while (exe)
	{
		tmp_str = quote_removal(parameter_expansion(exe->word, env));
		free(exe->word);
		exe->word = tmp_str;
		exe = exe->next;
	}
}

void	cmds_expansion(t_cmd_lst *cmds, t_dict *env)
{
	t_cmd_node	*cmd;

	cmd = cmds->head;
	while (cmd)
	{
		cmd->exes = exes_expansion(cmd->exes, env);
		cmd = cmd->next;
	}
}
