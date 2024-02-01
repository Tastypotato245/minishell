/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_document.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:38:37 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/01 16:38:38 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <here_document.h>

void	here_doc_traverse(t_tree *tree, t_list **here_doc_list)
{
	t_tree	*tree_left;

	if (tree == NULL
		|| tree->category == TR_WORD
		|| tree->category == TR_REDIRECT_IN
		|| tree->category == TR_REDIRECT_OUT
		|| tree->category == TR_REDIRECT_APPEND)
		return ;
	if (tree->category == TR_REDIRECT_HERE_DOC)
	{
		tree_left = tree->left;
		printf("here_doc_traverse() %d\n", tree->category);
		printf("here_doc_traverse(%s)\n", (char *)tree_left->left);
	}
	else
	{
		here_doc_traverse(tree->left, here_doc_list);
		here_doc_traverse(tree->right, here_doc_list);
	}

}
