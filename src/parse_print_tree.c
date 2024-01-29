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

#include <parse.h>

void	print_tree(t_tree *tree, int step)
{
	int	i;

	if (tree == NULL)
		return ;
	i = 0;
	while (i++ < step)
		printf("    ");
	if (tree->category == TR_LIST_AND)
		printf("TR_LIST_AND\n");
	if (tree->category == TR_LIST_OR)
		printf("TR_LIST_OR\n");
	if (tree->category == TR_LIST_END)
		printf("TR_LIST_END\n");
	if (tree->category == TR_PIPE_CONTINUE)
		printf("TR_PIPE_CONTINUE\n");
	if (tree->category == TR_PIPE_END)
		printf("TR_PIPE_END\n");
	if (tree->category == TR_SMPL_CMD_CONTINUE)
		printf("TR_SMPL_CMD_CONTINUE\n");
	if (tree->category == TR_SMPL_CMD_END)
		printf("TR_SMPL_CMD_END\n");
	if (tree->category == TR_WORD)
	{
		printf("TR_WORD(%s)\n", (char *)tree->left);
		return ;
	}
	if (tree->category == TR_REDIRECT_IN)
	{
		printf("TR_REDIRECT_IN(%s)\n", (char *)((t_tree *)tree->left)->left);
		return ;
	}
	if (tree->category == TR_REDIRECT_OUT)
	{
		printf("TR_REDIRECT_OUT(%s)\n", (char *)((t_tree *)tree->left)->left);
		return ;
	}
	if (tree->category == TR_REDIRECT_APPEND)
	{
		printf("TR_REDIRECT_APPEND(%s)\n", (char *)((t_tree *)tree->left)->left);
		return ;
	}
	if (tree->category == TR_REDIRECT_HERE_DOC)
	{
		printf("TR_REDIRECT_HERE_DOC(%s)\n", (char *)((t_tree *)tree->left)->left);
		return ;
	}
	print_tree(tree->left, step + 1);
	print_tree(tree->right, step);
}
