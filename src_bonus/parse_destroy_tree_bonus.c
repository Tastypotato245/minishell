/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_destroy_tree_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:09:23 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:09:27 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse_bonus.h>

t_tree	*destroy_tree(t_tree *tree)
{
	if (tree == NULL)
		return (NULL);
	if (tree->category == TR_WORD)
	{
		free(tree->left);
		free(tree);
		return (NULL);
	}
	destroy_tree(tree->left);
	destroy_tree(tree->right);
	free(tree);
	return (NULL);
}
