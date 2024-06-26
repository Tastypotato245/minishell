/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipex_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:06:19 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:06:20 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execute_bonus.h>
#include <expansion_bonus.h>

void	repeat_redirection(t_rd_lst *rds, t_dict *env)
{
	int			rd_fd;
	t_rd_node	*rd;

	rd = rds->head;
	while (rd)
	{
		if (expand_is_ambiguous(rd, env))
		{
			print_error(NULL, rd->file, "ambiguous redirect");
			exit(1);
		}
		rd_fd = open_guard(rd->rd_type, rd->file);
		if (rd->rd_type == IN_RD || rd->rd_type == HEREDOC_RD)
			func_guard(dup2(rd_fd, STDIN_FILENO), \
					PROGRAM_NAME, "repeat_redirection().");
		else
			func_guard(dup2(rd_fd, STDOUT_FILENO), \
					PROGRAM_NAME, "repeat_redirection().");
		func_guard(close(rd_fd), PROGRAM_NAME, "repeat_redirection().");
		rd = rd->next;
	}
}

int	open_guard_no_exit(int mod, char *file)
{
	int	fd;

	fd = -1;
	if (mod == IN_RD || mod == HEREDOC_RD)
		fd = open(file, O_RDONLY);
	else if (mod == OUT_RD)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (mod == APPEND_RD)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	return (fd);
}

int	open_guard(int mod, char *file)
{
	int	fd;

	fd = -1;
	if (mod == IN_RD || mod == HEREDOC_RD)
		fd = open(file, O_RDONLY);
	else if (mod == OUT_RD)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (mod == APPEND_RD)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		exit_handler(1, PROGRAM_NAME, file);
	return (fd);
}

char	**lst_to_2darr(t_exe_lst *exes)
{
	char		**s_cmd;
	t_exe_node	*exe;
	int			i;

	s_cmd = null_guard(malloc(sizeof(char *) * (exes->size + 1)), \
			PROGRAM_NAME, "lst_to_2darr().");
	i = 0;
	exe = exes->head;
	while (exe)
	{
		s_cmd[i] = ft_strdup(exe->word);
		exe = exe->next;
		++i;
	}
	s_cmd[i] = NULL;
	return (s_cmd);
}
