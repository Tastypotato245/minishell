/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:19:20 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:23:23 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_BONUS_H
# define BUILTIN_BONUS_H

# include <minishell_bonus.h>
# include <kyusulib_bonus.h>
# include <dict_bonus.h>
# include <list_bonus.h>

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

// builtin_ctl1.c
void	print_error(char *cmd, char *obj, char *str);
int		return_handler(int return_no, char *cmd, char *obj, char *str);

// builtin_ctl2.c
int		builtin_checker(t_cmd_node *cmd);
int		builtin_switcher(t_cmd_node *cmd, t_dict *env, int builtin_case);

// builtin functions
int		builtin_echo(t_exe_lst *exes);
int		builtin_cd(t_dict *env, t_exe_lst *exes);
int		builtin_pwd(void);
int		builtin_export(t_dict *env, t_exe_lst *exes);
int		builtin_unset(t_dict *env, t_exe_lst *exes);
int		builtin_env(t_dict *env, t_exe_lst *exes);
int		builtin_exit(t_dict *env, t_exe_lst *exes);

#endif
