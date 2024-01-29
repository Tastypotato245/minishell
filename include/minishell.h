/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:57:14 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/29 20:07:45 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../kyusulib/kyusulib.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include <readline/readline.h>

# define TRUE (1)
# define FALSE (0)
# define INFILE_O (0)
# define OUTFILE_O (1)
# define W_MOD_BS (0)
# define DEFAULT_PATH "/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin:."

# define PROGRAM_NAME "minishell"

/***** PIPEX *****/
typedef struct s_info
{
	int		ex_fd;
	pid_t	pnum;
	pid_t	pidx;
}				t_info;
/***** PIPEX *****/

/***** MINISHELL *****/
typedef enum e_rd_type
{
	IN_RD = 0,
	OUT_RD = 1,
	APPEND_RD = 2
}			t_rd_type;

typedef struct s_exe_node
{
	char				*word;
	struct s_exe_node	*next;
}				t_exe_node;

typedef struct s_exe_lst
{
	struct s_exe_node	*head;
	struct s_exe_node	*tail;
	int					size;
}				t_exe_lst;

typedef struct s_rd_node
{
	t_rd_type			rd_type;
	char				*file;
	struct s_rd_node	*next;
}				t_rd_node;

typedef struct s_rd_lst
{
	struct s_rd_node	*head;
	struct s_rd_node	*tail;
	int					size;
}				t_rd_lst;

typedef struct s_cmd_node
{
	struct s_exe_lst	*exes;
	struct s_rd_lst		*rds;
	struct s_cmd_node	*next;
}				t_cmd_node;

typedef struct s_cmd_lst
{
	struct s_cmd_node	*head;
	struct s_cmd_node	*tail;
	int					size;
}				t_cmd_lst;

// print_frankshell_image.c
void	print_frankshell_image(void);

// exe_lst_ctl.c
t_exe_lst	*new_exe_lst(void);
void		exe_lst_new_back(t_exe_lst *exes, char *word);
void		free_exe_lst(t_exe_lst *exes);
void		print_exe_lst(t_exe_lst *exes);

// rd_lst_ctl.c
t_rd_lst	*new_rd_lst(void);
void		rd_lst_new_back(t_rd_lst *rds, t_rd_type rd_type, char *file);
void		free_rd_lst(t_rd_lst *rds);
void		print_rd_lst(t_rd_lst *rds);

// cmd_lst_ctl.c
t_cmd_lst	*new_cmd_lst(void);
void		cmd_lst_new_back(t_cmd_lst *cmds, t_exe_lst *exes, t_rd_lst *rds);
void		free_cmd_lst(t_cmd_lst *cmds);
void		print_cmd_lst(t_cmd_lst *cmds);

// execute_test.c
void		execute_test(void);
/***** MINISHELL *****/


/***** PIPEX *****/
// pipex.c
void	pipex(int argc, char **argv, char **env);
int		open_guard(int mod, char *file);

// process.c
void	children_switch(t_info *info, int *fd, char **argv, char **env);

// access.c
void	exec(char *cmd, char **env);
char	*get_cmd(char *cmd, char **env, int flag);
/***** PIPEx *****/

#endif
