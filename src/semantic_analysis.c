/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semantic_analysis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:20:16 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/06 13:22:21 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semantic_analysis.h>

static int	semantic_analysis_list(t_tree *tree);

static int	semantic_analysis_pipe(t_tree *tree)
{
	t_tree	*tree_right;

	tree_right = tree->right;
	if (tree->category == TR_LIST_AND
		|| tree->category == TR_LIST_OR
		|| tree->category == TR_LIST_END)
	{
		if (tree_right != NULL)
			return (1);
		return (semantic_analysis_list(tree));
	}
	return (0);
}

static int	semantic_analysis_list(t_tree *tree)
{
	if (semantic_analysis_pipe(tree->left))
		return (1);
	if (tree->category == TR_LIST_AND
		|| tree->category == TR_LIST_OR)
		return (semantic_analysis_list(tree->right));
	return (0);
}

int	semantic_analysis(t_tree *tree)
{
	return (semantic_analysis_list(tree));
}
