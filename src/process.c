/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:09:20 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/29 20:07:49 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	first_child(t_info *info, int *fd, char **argv, char **env)
{
	int	infile_fd;

	func_guard(close(fd[0]), PROGRAM_NAME, "first_child().");
	infile_fd = open_guard(INFILE_O, argv[1]);
	func_guard(dup2(infile_fd, STDIN_FILENO), PROGRAM_NAME, "first_child().");
	func_guard(close(infile_fd), PROGRAM_NAME, "first_child().");
	func_guard(dup2(fd[1], STDOUT_FILENO), PROGRAM_NAME, "first_child().");
	func_guard(close(fd[1]), PROGRAM_NAME, "first_child().");
	exec(argv[2 + info->pidx], env);
}

void	middle_child(t_info *info, int *fd, char **argv, char **env)
{
	func_guard(close(fd[0]), PROGRAM_NAME, "middle_child().");
	func_guard(dup2(info->ex_fd, STDIN_FILENO), \
			PROGRAM_NAME, "middle_child().");
	func_guard(close(info->ex_fd), PROGRAM_NAME, "middle_child().");
	func_guard(dup2(fd[1], STDOUT_FILENO), PROGRAM_NAME, "middle_child().");
	func_guard(close(fd[1]), PROGRAM_NAME, "middle_child().");
	exec(argv[2 + info->pidx], env);
}

void	last_child(t_info *info, char **argv, char **env)
{
	int	outfile_fd;

	outfile_fd = open_guard(OUTFILE_O, argv[2 + info->pidx + 1]);
	func_guard(dup2(info->ex_fd, STDIN_FILENO), PROGRAM_NAME, "last_child().");
	func_guard(close(info->ex_fd), PROGRAM_NAME, "last_child().");
	func_guard(dup2(outfile_fd, STDOUT_FILENO), PROGRAM_NAME, "last_child().");
	func_guard(close(outfile_fd), PROGRAM_NAME, "last_child().");
	exec(argv[2 + info->pidx], env);
}

void	children_switch(t_info *info, int *fd, char **argv, char **env)
{
	if (info->pidx == 0)
		first_child(info, fd, argv, env);
	else if (info->pidx == info->pnum - 1)
		last_child(info, argv, env);
	else
		middle_child(info, fd, argv, env);
}
