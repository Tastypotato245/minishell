/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:51:19 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/01 20:05:21 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <minishell.h>
# include <kyusulib.h>
# include <dict.h>
# include <list.h>

# define BTIN_ECHO			"echo"
# define BTIN_CD			"cd"
# define BTIN_PWD			"pwd"
# define BTIN_EXPORT		"export"
# define BTIN_UNSET			"unset"
# define BTIN_ENV			"env"
# define BTIN_EXIT			"exit"

# define NONE_BTIN_CASE		(0)
# define BTIN_CASE_ECHO		(1)
# define BTIN_CASE_CD		(2)
# define BTIN_CASE_PWD		(3)
# define BTIN_CASE_EXPORT	(4)
# define BTIN_CASE_UNSET	(5)
# define BTIN_CASE_ENV		(6)
# define BTIN_CASE_EXIT		(7)

void	print_error(char *cmd, char *obj, char *str);
int		return_handler(int return_no, char *cmd, char *obj, char *str);
int		builtin_checker(t_cmd_node *cmd);
int		builtin_switcher(t_cmd_node *cmd, t_dict *env, int builtin_case);

int		builtin_echo(t_exe_lst *exes);
int		builtin_cd(void);
int		builtin_pwd(void);
int		builtin_export(t_dict *env, t_exe_lst *exes);
int		builtin_unset(t_dict *env, t_exe_lst *exes);
int		builtin_env(t_dict *env, t_exe_lst *exes);
void	builtin_exit(t_exe_lst *exes);

#endif
