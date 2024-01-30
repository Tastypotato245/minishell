/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:09:20 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/30 11:32:27 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	single_child(t_cmd_node *cmd, char **env)
{
	repeat_redirection(cmd->rds);
	exec(cmd->exes, env);
}

void	first_child(int *fd, t_cmd_node *cmd, char **env)
{
	func_guard(close(fd[0]), PROGRAM_NAME, "close(fd[0]): first_child().");
	repeat_redirection(cmd->rds);
	func_guard(dup2(fd[1], STDOUT_FILENO), PROGRAM_NAME, "dup2(fd[1]): first_child().");
	func_guard(close(fd[1]), PROGRAM_NAME, "close(fd[1]): first_child().");
	exec(cmd->exes, env);
}

void	middle_child(t_info *info, int *fd, t_cmd_node *cmd, char **env)
{
	func_guard(close(fd[0]), PROGRAM_NAME, "middle_child().");
	func_guard(dup2(info->ex_fd, STDIN_FILENO), PROGRAM_NAME, "middle_child().");
	func_guard(close(info->ex_fd), PROGRAM_NAME, "middle_child().");
	repeat_redirection(cmd->rds);
	func_guard(dup2(fd[1], STDOUT_FILENO), PROGRAM_NAME, "middle_child().");
	func_guard(close(fd[1]), PROGRAM_NAME, "middle_child().");
	exec(cmd->exes, env);
}

void	last_child(t_info *info, t_cmd_node *cmd, char **env)
{
	func_guard(dup2(info->ex_fd, STDIN_FILENO), PROGRAM_NAME, "last_child().");
	func_guard(close(info->ex_fd), PROGRAM_NAME, "last_child().");
	repeat_redirection(cmd->rds);
	exec(cmd->exes, env);
}

void	children_switch(t_info *info, int *fd, t_cmd_node *cmd, char **env)
{
	if (info->pidx == 0)
		first_child(fd, cmd, env);
	else if (info->pidx == info->pnum - 1)
		last_child(info, cmd, env);
	else
		middle_child(info, fd, cmd, env);
}
