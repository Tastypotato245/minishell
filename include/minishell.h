/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:57:14 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/28 22:47:17 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../kyusulib/kyusulib.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>

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

typedef	struct s_exe_lst
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

typedef	struct s_rd_lst
{
	struct s_rd_node	*head;
	struct s_rd_node	*tail;
	int					size;
}				t_rd_lst;

typedef struct s_cmd_node
{
	t_exe_lst			*exes;
	t_rd_lst			*rds;
	struct s_node_cmd	*next;
}				t_cmd_node;

typedef	struct s_cmd_lst
{
	struct s_cmd_node	*head;
	struct s_cmd_node	*tail;
	int					size;
}				t_cmd_lst;

// print_frankshell_image.c
void	print_frankshell_image(void);

#endif
