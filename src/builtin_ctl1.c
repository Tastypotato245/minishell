/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_ctl1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:27:34 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/06 14:28:09 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expansion.h>
#include <builtin.h>
#include <kyusulib.h>
#include <minishell.h>
#include <execute.h>

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

static void	save_n_load_stdin_n_out(char mod, int *stdin_fd, int *stdout_fd)
{
	if (mod == 's')
	{
		(*stdin_fd) = func_guard(dup(STDIN_FILENO), PROGRAM_NAME, \
				"save stdin_fd: save_n_load_stdin_n_out().");
		(*stdout_fd) = func_guard(dup(STDOUT_FILENO), PROGRAM_NAME, \
				"save stdout_fd: save_n_load_stdin_n_out().");
	}
	else if (mod == 'l')
	{
		func_guard(dup2(*stdin_fd, STDIN_FILENO), PROGRAM_NAME, \
				"load stdin_fd: save_n_load_stdin_n_out().");
		func_guard(dup2(*stdout_fd, STDOUT_FILENO), PROGRAM_NAME, \
				"load stdout_fd: save_n_load_stdin_n_out().");
		func_guard(close(*stdin_fd), PROGRAM_NAME, \
				"close stdin_fd: save_n_load_stdin_n_out().");
		func_guard(close(*stdout_fd), PROGRAM_NAME, \
				"close stdout_fd: save_n_load_stdin_n_out().");
	}
}

int	builtin_switcher(t_cmd_node *cmd, t_dict *env, int builtin_case)
{
	int	rt_val;
	int	stdin_fd;
	int	stdout_fd;

	rt_val = 127;
	save_n_load_stdin_n_out('s', &stdin_fd, &stdout_fd);
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
		rt_val = builtin_exit(cmd->exes);
	save_n_load_stdin_n_out('l', &stdin_fd, &stdout_fd);
	return (rt_val);
}
