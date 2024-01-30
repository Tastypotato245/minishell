/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:56:13 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/30 11:32:27 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// func_guard(unlink(HD_FILE));
// sequencial unlink 
static void	parent_wait(t_info *info, pid_t last_pid)
{
	int	i;
	int	exit_save;
	int	status;

	i = -1;
	while (++i < info->pnum)
	{
		if (wait(&status) == last_pid)
			exit_save = WEXITSTATUS(status);
	}
	exit(exit_save);
}

void	multiple_proccess(t_cmd_lst *cmds, char **env)
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
	parent_wait(&info, pid);
}

void	single_proccess(t_cmd_node *cmd, char **env)
{
	pid_t		pid;
	int		status;

	pid = func_guard(fork(), PROGRAM_NAME, "pipex().");
	if (pid == 0)
		single_child(cmd, env);
	wait(&status);
	exit(WEXITSTATUS(status));
}

void	pipex(t_cmd_lst *cmds, char **env)
{
	if (cmds->size == 1)
		single_proccess(cmds->head, env);
	else if (cmds->size > 1)
		multiple_proccess(cmds, env);
	printf("There is no cmd\n");
}
