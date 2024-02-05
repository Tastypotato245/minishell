/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_ctl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:26:41 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/05 22:50:31 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expansion.h>
#include <stdlib.h>

static void	exes_append(t_exe_lst *dst_exes, t_exe_lst *src_exes)
{
	if (dst_exes->size == 0)
		dst_exes->head = src_exes->head;
	else
		dst_exes->tail->next = src_exes->head;
	dst_exes->tail = src_exes->tail;
	dst_exes->size += src_exes->size;
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

	final_exes = new_exe_lst();
	exe = exes->head;
	while (exe)
	{
		tmp_exes = filename_expansion(parameter_expansion(exe->word, env));
		exes_quote_removal(tmp_exes);
		exes_append(final_exes, tmp_exes);
		exe = exe->next;
	}
	free_exe_lst(exes);
	return (final_exes);
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

int	expand_is_ambiguous(t_rd_node *rd, t_dict *env)
{
	t_exe_lst	*exes;
	char		*buf;

	buf = parameter_expansion(rd->file, env);
	exes = filename_expansion(buf);
	free(buf);
	if (exes->size > 1)
		return (1);
	free(rd->file);
	rd->file = quote_removal(exes->head->word);
	return (0);
}
