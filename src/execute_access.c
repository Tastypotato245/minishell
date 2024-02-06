/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_access.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:42:53 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/06 13:20:38 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execute.h>

static char	*get_paths(t_dict *env)
{
	return (find_val_in_dict(env, "PATH"));
}

static void	absolute_or_relative_path(char **s_cmd, t_dict *env)
{
	if (access(s_cmd[0], F_OK) == -1)
		exit_handler(127, PROGRAM_NAME, s_cmd[0]);
	if (execve(s_cmd[0], s_cmd, to_2darr(env)) == -1)
		exit_handler(126, PROGRAM_NAME, s_cmd[0]);
}


//printf("*** path: %s\n", path);
//printf("*** s_cmd0: %s\n", s_cmd[0]);
//printf("*** s_cmd1: %s\n", s_cmd[1]);
void	exec(t_exe_lst *exes, t_dict *env)
{
	char	**s_cmd;
	char	*path;
	char	*exist_path;

	if (exes->size == 0)
		exit (0);
	s_cmd = lst_to_2darr(exes);
	if (ft_strchr(s_cmd[0], '/') != NULL)
		absolute_or_relative_path(s_cmd, env);
	else
	{
		path = get_cmd(s_cmd[0], env, F_OK | X_OK);
		exist_path = get_cmd(s_cmd[0], env, F_OK);
		if (access(path, F_OK) == -1 && access(exist_path, F_OK) == -1)
			exit_handler(127, PROGRAM_NAME, s_cmd[0]);
		if (execve(path, s_cmd, to_2darr(env)) == -1)
			exit_handler(126, PROGRAM_NAME, path);
	}
}

char	*get_cmd(char *cmd, t_dict *env, int flag)
{
	int		i;
	char	*exec;
	char	**allpath;
	char	*path_part;
	char	**s_cmd;

	i = -1;
	allpath = ft_split(get_paths(env), ':');
	s_cmd = ft_split(cmd, ' ');
	while (allpath && allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, s_cmd[0]);
		free(path_part);
		if (access(exec, flag) == 0)
		{
			free_strarr(allpath);
			free_strarr(s_cmd);
			return (exec);
		}
		free(exec);
	}
	free_strarr(allpath);
	free_strarr(s_cmd);
	return (NULL);
}
