/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:52:23 by younghoc          #+#    #+#             */
/*   Updated: 2024/01/30 20:13:40 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <traverse.h>
#include <panic.h>
#include <execute.h>

static void	traverse_smpl_cmd(t_exe_lst *exes, t_rd_lst *rds, t_tree *tree)
{
	t_tree	*tree_left;

	if (tree->category != TR_SMPL_CMD_CONTINUE
		&& tree->category != TR_SMPL_CMD_END)
		panic("traverse_pipe()");
	tree_left = tree->left;
	if (tree_left->category == TR_WORD)
		exe_lst_new_back(exes, ft_strdup(tree_left->left));
	else if (tree_left->category == TR_REDIRECT_IN)
		rd_lst_new_back(rds, IN_RD,
			ft_strdup(((t_tree *)tree_left->left)->left));
	else if (tree_left->category == TR_REDIRECT_OUT)
		rd_lst_new_back(rds, OUT_RD,
			ft_strdup(((t_tree *)tree_left->left)->left));
	else if (tree_left->category == TR_REDIRECT_APPEND)
		rd_lst_new_back(rds, APPEND_RD,
			ft_strdup(((t_tree *)tree_left->left)->left));
	else
		panic("traverse_smpl_cmd(): unhandled case");
	if (tree->category == TR_SMPL_CMD_CONTINUE)
		traverse_smpl_cmd(exes, rds, tree->right);
}

static void	traverse_pipe(t_cmd_lst *cmds, t_tree *tree)
{
	t_exe_lst	*exes;
	t_rd_lst	*rds;

	if (DEBUG)
	{
		printf("----------\n");
		print_tree(tree, 0);
		printf("----------\n");
	}
	if (tree->category != TR_PIPE_CONTINUE
		&& tree->category != TR_PIPE_END)
		panic("traverse_pipe()");
	exes = new_exe_lst();
	rds = new_rd_lst();
	traverse_smpl_cmd(exes, rds, tree->left);
	cmd_lst_new_back(cmds, exes, rds);
	if (tree->category == TR_PIPE_CONTINUE)
		traverse_pipe(cmds, tree->right);
}

void	traverse(t_tree *tree, char **envp)
{
	t_cmd_lst	*cmds;

	if (tree == NULL)
		return ;
	if (tree->category == TR_PIPE_CONTINUE
		|| tree->category == TR_PIPE_END)
	{
		cmds = new_cmd_lst();
		traverse_pipe(cmds, tree);
		if (DEBUG)
			print_cmd_lst(cmds);
		pipex(cmds, envp);
		free_cmd_lst(cmds);
	}
	else
	{
		traverse(tree->left, envp);
		traverse(tree->right, envp);
	}
}
