/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:42:34 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/07 13:03:30 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execute.h>
#include <builtin.h>
#include <expansion.h>
#include <signal_handler.h>

// func_guard(unlink(HD_FILE));
// sequencial unlink 
static int	parent_wait(t_info *info, pid_t last_pid)
{
	int	i;
	int	exit_save;
	int	status;

	i = -1;
	exit_save = 0;
	status = 0;
	while (++i < info->pnum)
	{
		if (wait(&status) == last_pid)
		{
			if (WEXITSTATUS(status))
				exit_save = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
			{
				if (status == 2)
					ft_putendl_fd("", STDERR_FILENO);
				else if (status == 3)
					ft_putendl_fd("Quit: 3", STDERR_FILENO);
				exit_save = WTERMSIG(status) + 128;
			}
		}
	}
	set_signal(0);
	return (exit_save);
}

static int	multiple_proccess(t_cmd_lst *cmds, t_dict *env)
{
	int			fd[2];
	pid_t		pid;
	t_info		info;
	t_cmd_node	*cmd;

	info.pnum = cmds->size;
	ft_bzero(fd, sizeof(int) * 2);
	info.pidx = 0;
	cmd = cmds->head;
	while (info.pidx < info.pnum)
	{
		info.ex_fd = fd[0];
		if (info.pidx != info.pnum - 1 && pipe(fd) == -1)
			exit_handler(1, PROGRAM_NAME, "pipex().");
		pid = func_guard(fork(), PROGRAM_NAME, "pipex().");
		if (pid == 0)
			children_switch(&info, fd, cmd, env);
		if (pid > 0 && info.pidx != 0)
			func_guard(close(info.ex_fd), PROGRAM_NAME, "pipex().");
		if (pid > 0 && info.pidx != info.pnum - 1)
			func_guard(close(fd[1]), PROGRAM_NAME, "pipex().");
		++(info.pidx);
		cmd = cmd->next;
	}
	return (parent_wait(&info, pid));
}

static int	single_proccess(t_cmd_node *cmd, t_dict *env)
{
	pid_t	pid;
	int		status;
	int		builtin_case;
	int		exit_save;

	exit_save = 0;
	status = 0;
	builtin_case = builtin_checker(cmd);
	if (builtin_case != NONE_BTIN_CASE)
		return (builtin_switcher(cmd, env, builtin_case));
	pid = func_guard(fork(), PROGRAM_NAME, "pipex().");
	if (pid == 0)
		single_child(cmd, env);
	wait(&status);
	if (WEXITSTATUS(status))
		exit_save = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		if (status == 2)
			ft_putendl_fd("", STDERR_FILENO);
		else if (status == 3)
			ft_putendl_fd("Quit: 3", STDERR_FILENO);
		exit_save = WTERMSIG(status) + 128;
	}
	return (exit_save);
}

int	pipex(t_cmd_lst *cmds, t_dict *env)
{
	int	exit_code;

	exit_code = 0;
	cmds_expansion(cmds, env);
	set_signal(2);
	if (cmds->size == 1)
		exit_code = single_proccess(cmds->head, env);
	else if (cmds->size > 1)
		exit_code = multiple_proccess(cmds, env);
	set_signal(0);
	return (exit_code);
}
