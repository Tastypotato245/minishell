/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_print_tree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:51:37 by younghoc          #+#    #+#             */
/*   Updated: 2024/01/29 15:51:38 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <panic.h>
#include <parse.h>

static int	print_tree1(t_tree *tree)
{
	if (tree->category == TR_LIST_AND)
		printf("TR_LIST_AND\n");
	else if (tree->category == TR_LIST_OR)
		printf("TR_LIST_OR\n");
	else if (tree->category == TR_LIST_END)
		printf("TR_LIST_END\n");
	else if (tree->category == TR_PIPE_CONTINUE)
		printf("TR_PIPE_CONTINUE\n");
	else if (tree->category == TR_PIPE_END)
		printf("TR_PIPE_END\n");
	else if (tree->category == TR_SMPL_CMD_CONTINUE)
		printf("TR_SMPL_CMD_CONTINUE\n");
	else if (tree->category == TR_SMPL_CMD_END)
		printf("TR_SMPL_CMD_END\n");
	else
		return (-1);
	return (0);
}

static int	print_tree2(t_tree *tree)
{
	if (tree->category == TR_WORD)
		printf("TR_WORD(%s)\n",
			(char *)tree->left);
	else if (tree->category == TR_REDIRECT_IN)
		printf("TR_REDIRECT_IN(%s)\n",
			(char *)((t_tree *)tree->left)->left);
	else if (tree->category == TR_REDIRECT_OUT)
		printf("TR_REDIRECT_OUT(%s)\n",
			(char *)((t_tree *)tree->left)->left);
	else if (tree->category == TR_REDIRECT_APPEND)
		printf("TR_REDIRECT_APPEND(%s)\n",
			(char *)((t_tree *)tree->left)->left);
	else if (tree->category == TR_REDIRECT_HERE_DOC)
		printf("TR_REDIRECT_HERE_DOC(%s)\n",
			(char *)((t_tree *)tree->left)->left);
	else
		return (-1);
	return (0);
}

void	print_tree(t_tree *tree, int step)
{
	int	i;

	if (tree == NULL)
		return ;
	i = 0;
	while (i++ < step)
		printf("    ");
	if (print_tree1(tree) == -1)
	{
		if (print_tree2(tree) == -1)
			panic("print_tree(): not handled case");
		return ;
	}
	print_tree(tree->left, step + 1);
	print_tree(tree->right, step);
}
