/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:51:19 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/31 20:15:02 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <minishell.h>
# include <kyusulib.h>
# include <dict.h>
# include <list.h>

int		builtin_checker(t_cmd_node *cmd, t_dict *env);
void	builtin_switcher(t_cmd_node *cmd, t_dict *env);

void	builtin_echo(void);
void	builtin_cd(void);
void	builtin_pwd(void);
void	builtin_env(t_dict *env_dict);
void	builtin_export(t_dict *env_dict, t_exe_lst *exes);
void	builtin_unset(t_dict *env_dict, t_exe_lst *exes);
void	builtin_exit(void);

#endif
