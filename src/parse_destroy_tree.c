/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_destroy_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:42:30 by younghoc          #+#    #+#             */
/*   Updated: 2024/01/31 16:42:31 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>

t_tree	*destroy_tree(t_tree *tree)
{
	if (tree != NULL)
		return (NULL);
	destroy_tree(tree->left);
	destroy_tree(tree->right);
	free(tree);
	return (NULL);
}
