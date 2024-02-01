/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_ctl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:51:10 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/01 20:47:43 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <execute.h>
#include <dict.h>
#include <list.h>

void	print_error(char *cmd, char *obj, char *str)
{
	ft_putstr_fd(PROGRAM_NAME, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	if (obj != NULL)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd("`", STDERR_FILENO);
		ft_putstr_fd(obj, STDERR_FILENO);
		ft_putstr_fd("\'", STDERR_FILENO);
	}
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(str, STDERR_FILENO);
}

int	return_handler(int return_no, char *cmd, char *obj, char *str)
{
	print_error(cmd, obj, str);
	return (return_no);
}

int	builtin_checker(t_cmd_node *cmd)
{
	char	*builtin_cmd;
	int		len;

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

int	builtin_switcher(t_cmd_node *cmd, t_dict *env, int builtin_case)
{
	if (DEBUG)
		printf("\t * now builtin command: %d\n", builtin_case);
	repeat_redirection(cmd->rds);
	if (builtin_case == BTIN_CASE_ECHO)
		return (builtin_echo(cmd->exes));
	else if (builtin_case == BTIN_CASE_CD)
		return (builtin_cd());
	else if (builtin_case == BTIN_CASE_PWD)
		return (builtin_pwd());
	else if (builtin_case == BTIN_CASE_EXPORT)
		return (builtin_export(env, cmd->exes));
	else if (builtin_case == BTIN_CASE_UNSET)
		return (builtin_unset(env, cmd->exes));
	else if (builtin_case == BTIN_CASE_ENV)
		return (builtin_env(env, cmd->exes));
	else if (builtin_case == BTIN_CASE_EXIT)
		builtin_exit();
	return (127);
}
