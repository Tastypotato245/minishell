/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:09:56 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:09:57 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse_bonus.h>
#include <tokenize_bonus.h>
#include <panic_bonus.h>

static t_tree	*parse_list_end(t_tree *tree)
{
	tree->category = TR_LIST_END;
	tree->right = NULL;
	return (tree);
}

static t_tree	*parse_list_and(t_list **tokens, t_tree *tree)
{
	tree->category = TR_LIST_AND;
	*tokens = (*tokens)->next;
	tree->right = parse_list(tokens);
	if (tree->right == NULL)
		return (destroy_tree(tree));
	return (tree);
}

static t_tree	*parse_list_or(t_list **tokens, t_tree *tree)
{
	tree->category = TR_LIST_OR;
	*tokens = (*tokens)->next;
	tree->right = parse_list(tokens);
	if (tree->right == NULL)
		return (destroy_tree(tree));
	return (tree);
}

t_tree	*parse_list(t_list **tokens)
{
	t_tree	*tree;
	t_token	*token;

	tree = null_guard(ft_calloc(1, sizeof(t_tree)),
			PROGRAM_NAME, "parse_list().");
	tree->left = parse_pipeline(tokens);
	if (tree->left == NULL)
		return (destroy_tree(tree));
	if (*tokens == NULL)
		return (parse_list_end(tree));
	token = (*tokens)->content;
	if (token->category == T_AND)
		return (parse_list_and(tokens, tree));
	else if (token->category == T_OR)
		return (parse_list_or(tokens, tree));
	else if (token->category == T_R_PAREN)
		return (parse_list_end(tree));
	return (print_parse_error(*tokens, tree));
}
