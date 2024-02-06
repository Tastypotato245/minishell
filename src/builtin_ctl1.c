/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_ctl1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:57:20 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/06 12:32:20 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <execute.h>
#include <dict.h>
#include <list.h>
#include <expansion.h>

int	builtin_checker(t_cmd_node *cmd)
{
	char	*builtin_cmd;
	int		len;

	if (cmd->exes->size == 0)
		return (NONE_BTIN_CASE);
	builtin_cmd = cmd->exes->head->word;
	len = ft_strlen(builtin_cmd);
	if (len == 4 && ft_strncmp(builtin_cmd, BTIN_ECHO, len) == 0)
		return (BTIN_CASE_ECHO);
	else if (len == 2 && ft_strncmp(builtin_cmd, BTIN_CD, len) == 0)
		return (BTIN_CASE_CD);
	else if (len == 3 && ft_strncmp(builtin_cmd, BTIN_PWD, len) == 0)
		return (BTIN_CASE_PWD);
	else if (len == 6 && ft_strncmp(builtin_cmd, BTIN_EXPORT, len) == 0)
		return (BTIN_CASE_EXPORT);
	else if (len == 5 && ft_strncmp(builtin_cmd, BTIN_UNSET, len) == 0)
		return (BTIN_CASE_UNSET);
	else if (len == 3 && ft_strncmp(builtin_cmd, BTIN_ENV, len) == 0)
		return (BTIN_CASE_ENV);
	else if (len == 4 && ft_strncmp(builtin_cmd, BTIN_EXIT, len) == 0)
		return (BTIN_CASE_EXIT);
	return (NONE_BTIN_CASE);
}

static int	repeat_redirection_with_return(t_rd_lst *rds, t_dict *env)
{
	int			rd_fd;
	t_rd_node	*rd;

	rd = rds->head;
	while (rd)
	{
		if (expand_is_ambiguous(rd, env))
			return (return_handler(1, NULL, rd->file, "ambiguous redirect"));
		rd_fd = open_guard_no_exit(rd->rd_type, rd->file);
		if (rd->rd_type == IN_RD || rd->rd_type == HEREDOC_RD)
		{
			if (rd_fd == -1 || dup2(rd_fd, STDIN_FILENO) == -1)
				return (return_handler(1, rd->file, NULL, strerror(errno)));
		}
		else
		{
			if (rd_fd == -1 || dup2(rd_fd, STDOUT_FILENO) == -1)
				return (return_handler(1, rd->file, NULL, strerror(errno)));
		}
		if (close(rd_fd) == -1)
			return (return_handler(1, rd->file, NULL, strerror(errno)));
		rd = rd->next;
	}
	return (0);
}

int	builtin_switcher(t_cmd_node *cmd, t_dict *env, int builtin_case)
{
//	const int	stdin_fd = ;
//	const int	stdout_fd = ;
	int	rt_val;

	rt_val = 127;
	if (DEBUG)
		printf("\t * now builtin command: %d\n", builtin_case);
	// 임시로 stdin 과 stdout을 dup 떠놓고
	if (repeat_redirection_with_return(cmd->rds, env))
		return (1);
	if (builtin_case == BTIN_CASE_ECHO)
		rt_val = builtin_echo(cmd->exes);
	else if (builtin_case == BTIN_CASE_CD)
		rt_val = builtin_cd(env, cmd->exes);
	else if (builtin_case == BTIN_CASE_PWD)
		rt_val = builtin_pwd();
	else if (builtin_case == BTIN_CASE_EXPORT)
		rt_val = builtin_export(env, cmd->exes);
	else if (builtin_case == BTIN_CASE_UNSET)
		rt_val = builtin_unset(env, cmd->exes);
	else if (builtin_case == BTIN_CASE_ENV)
		rt_val = builtin_env(env, cmd->exes);
	else if (builtin_case == BTIN_CASE_EXIT)
		builtin_exit(cmd->exes);
	//funcdup();
	// stdin 과 stdout을 돌려놓아야 함
	return (rt_val);
}
