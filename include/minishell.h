/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:57:14 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/29 16:23:38 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../kyusulib/kyusulib.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>

# define PROGRAM_NAME "minishell"

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

// rd_lst_ctl.c
t_rd_lst	*new_rd_lst(void);
void		rd_lst_new_back(t_rd_lst *rds, t_rd_type rd_type, char *file);
void		free_rd_lst(t_rd_lst *rds);

// cmd_lst_ctl.c
t_cmd_lst	*new_cmd_lst(void);
void		cmd_lst_new_back(t_cmd_lst *cmds, t_exe_lst *exes, t_rd_lst *rds);
void		free_cmd_lst(t_cmd_lst *cmds);

#endif
