/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:19:46 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:23:08 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_BONUS_H
# define EXECUTE_BONUS_H

# include <kyusulib_bonus.h>
# include <minishell_bonus.h>
# include <builtin_bonus.h>
# include <list_bonus.h>
# include <dict_bonus.h>
# include <fcntl.h>
# include <sys/wait.h>

# define TRUE (1)
# define FALSE (0)
# define INFILE_O (0)
# define OUTFILE_T_O (1)
# define OUTFILE_A_O (2)

typedef struct s_info
{
	int		ex_fd;
	pid_t	pnum;
	pid_t	pidx;
}				t_info;

// pipex.c
int		pipex(t_cmd_lst *cmds, t_dict *env);

// pipex_utils.c
void	repeat_redirection(t_rd_lst *rds, t_dict *env);
int		open_guard_no_exit(int mod, char *file);
int		open_guard(int mod, char *file);
char	**lst_to_2darr(t_exe_lst *exes);
int		expand_is_ambiguous(t_rd_node *rd, t_dict *env);

// process.c
void	single_child(t_cmd_node *cmd, t_dict *env);
void	children_switch(t_info *info, int *fd, t_cmd_node *cmd, t_dict *env);

// access.c
void	exec(t_exe_lst *exes, t_dict *env);
char	*get_cmd(char *cmd, t_dict *env, int flag);

#endif
