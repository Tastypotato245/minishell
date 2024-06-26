/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:13:57 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 14:25:09 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dict_bonus.h>
#include <minishell_bonus.h>
#include <traverse_bonus.h>
#include <panic_bonus.h>
#include <execute_bonus.h>

static int	traverse_list(t_tree *tree, t_dict *env_dict,
				int prev_exit_status, t_tree_category prev_category);

static void	traverse_word_and_redirect(t_exe_lst *exes,
		t_rd_lst *rds, t_tree *tree)
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
	else if (tree_left->category == TR_REDIRECT_HERE_DOC)
		rd_lst_new_back(rds, HEREDOC_RD,
			ft_strdup(((t_tree *)tree_left->left)->left));
	else
		panic("traverse_word_and_redirect(): unhandled case");
	if (tree->category == TR_SMPL_CMD_CONTINUE)
		traverse_word_and_redirect(exes, rds, tree->right);
}

static void	traverse_smpl_cmd(t_cmd_lst *cmds, t_tree *tree)
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
		panic("traverse_smpl_cmd()");
	exes = new_exe_lst();
	rds = new_rd_lst();
	traverse_word_and_redirect(exes, rds, tree->left);
	cmd_lst_new_back(cmds, exes, rds);
	if (tree->category == TR_PIPE_CONTINUE)
		traverse_smpl_cmd(cmds, tree->right);
}

static int	traverse_pipe(t_tree *tree, t_dict *env_dict)
{
	t_cmd_lst	*cmds;
	int			exit_status;
	t_tree		*tree_left;

	if (tree == NULL)
		panic("traverse_pipe()");
	tree_left = tree->left;
	if (tree_left->category == TR_LIST_AND
		|| tree_left->category == TR_LIST_OR
		|| tree_left->category == TR_LIST_END)
		return (traverse_list(tree_left, env_dict, 0, TR_LIST_AND));
	else if (tree_left->category == TR_SMPL_CMD_CONTINUE
		|| tree_left->category == TR_SMPL_CMD_END)
	{
		cmds = new_cmd_lst();
		traverse_smpl_cmd(cmds, tree);
		if (DEBUG)
			print_cmd_lst(cmds);
		exit_status = pipex(cmds, env_dict);
		dict_modi_val_or_new(env_dict, "?", ft_itoa(exit_status));
		free_cmd_lst(cmds);
		return (exit_status);
	}
	panic("traverse_pipe()");
	return (-1);
}

static int	traverse_list(t_tree *tree, t_dict *env_dict,
		int prev_exit_status, t_tree_category prev_category)
{
	int	left_exit_status;
	int	right_exit_status;

	left_exit_status = prev_exit_status;
	right_exit_status = -1;
	if (prev_category == TR_LIST_OR)
	{
		if (prev_exit_status != 0)
			left_exit_status = traverse_pipe(tree->left, env_dict);
	}
	else
	{
		if (prev_exit_status == 0)
			left_exit_status = traverse_pipe(tree->left, env_dict);
	}
	if (tree->category == TR_LIST_AND
		|| tree->category == TR_LIST_OR)
		right_exit_status = traverse_list(tree->right, env_dict,
				left_exit_status, tree->category);
	if (right_exit_status == -1)
		return (left_exit_status);
	return (right_exit_status);
}

int	traverse(t_tree *tree, t_dict *env_dict)
{
	return (traverse_list(tree, env_dict, 0, TR_LIST_AND));
}
