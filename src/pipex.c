/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:56:13 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/29 20:07:47 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// func_guard(unlink(HD_FILE));
// sequencial unlink 
static void	parent_wait(t_info *info, pid_t last_pid, int mod)
{
	int	i;
	int	exit_save;
	int	status;

	mod = 0;
	i = -1;
	while (++i < info->pnum)
	{
		if (wait(&status) == last_pid)
			exit_save = WEXITSTATUS(status);
	}
	exit(exit_save);
}

// 0 : <
// 1 : >
// 2 : >>
int	open_guard(int mod, char *file)
{
	int	fd;

	if (mod == 0)
		fd = open(file, O_RDONLY);
	if (mod == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (mod == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		exit_handler(1, PROGRAM_NAME, file);
	return (fd);
}

void	pipex(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid;
	t_info	info;

	info.pnum = argc - 3;
	fd[0] = 0;
	fd[1] = 0;
	info.pidx = 0;
	while (info.pidx < info.pnum)
	{
		info.ex_fd = fd[0];
		if (info.pidx != info.pnum - 1 && pipe(fd) == -1)
			exit_handler(1, PROGRAM_NAME, "pipex().");
		pid = func_guard(fork(), PROGRAM_NAME, "pipex().");
		if (pid == 0)
			children_switch(&info, fd, argv, env);
		if (pid > 0 && info.pidx != 0)
			func_guard(close(info.ex_fd), PROGRAM_NAME, "pipex().");
		if (pid > 0 && info.pidx != info.pnum - 1)
			func_guard(close(fd[1]), PROGRAM_NAME, "pipex().");
		++(info.pidx);
	}
	parent_wait(&info, pid, W_MOD_BS);
}
