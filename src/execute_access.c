/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_access.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:42:53 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/30 17:42:54 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execute.h>

static char	*get_paths(char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env && env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strncmp(sub, "PATH", 4) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (DEFAULT_PATH);
}

void	exec(t_exe_lst *exes, char **env)
{
	char	**s_cmd;
	char	*path;
	char	*exist_path;

	s_cmd = lst_to_2darr(exes);
	if (s_cmd[0][0] == '/' || ft_strncmp(s_cmd[0], "./", 2) == 0)
	{
		if (access(s_cmd[0], F_OK) == -1)
			exit_handler(127, PROGRAM_NAME, s_cmd[0]);
		if (execve(s_cmd[0], s_cmd, env) == -1)
			exit_handler(126, PROGRAM_NAME, s_cmd[0]);
	}
	else
	{
		path = get_cmd(s_cmd[0], env, F_OK | X_OK);
		exist_path = get_cmd(s_cmd[0], env, F_OK);
		if (access(path, F_OK) == -1 && access(exist_path, F_OK) == -1)
			exit_handler(127, PROGRAM_NAME, s_cmd[0]);
		if (ft_strncmp(path, s_cmd[0], ft_strlen(path)) == 0 && \
				ft_strchr(path, '/') == NULL)
			exit_handler(127, PROGRAM_NAME, s_cmd[0]);
		if (execve(path, s_cmd, env) == -1)
			exit_handler(126, PROGRAM_NAME, s_cmd[0]);
	}
}

char	*get_cmd(char *cmd, char **env, int flag)
{
	int		i;
	char	*exec;
	char	**allpath;
	char	*path_part;
	char	**s_cmd;

	i = -1;
	allpath = ft_split(get_paths(env), ':');
	s_cmd = ft_split(cmd, ' ');
	while (allpath[++i])
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
	return (cmd);
}
