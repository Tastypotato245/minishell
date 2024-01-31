/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:16:11 by younghoc          #+#    #+#             */
/*   Updated: 2024/01/31 13:16:13 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <tokenize.h>
#include <panic.h>

static void	set_tree_to_redirect_in(t_tree *tree, t_list **tokens)
{
	tree->category = TR_REDIRECT_IN;
	*tokens = (*tokens)->next;
	tree->left = parse_word(tokens);
	tree->right = NULL;
}

static void	set_tree_to_redirect_out(t_tree *tree, t_list **tokens)
{
	tree->category = TR_REDIRECT_OUT;
	*tokens = (*tokens)->next;
	tree->left = parse_word(tokens);
	tree->right = NULL;
}

static void	set_tree_to_redirect_append(t_tree *tree, t_list **tokens)
{
	tree->category = TR_REDIRECT_APPEND;
	*tokens = (*tokens)->next;
	tree->left = parse_word(tokens);
	tree->right = NULL;
}

static void	set_tree_to_here_doc(t_tree *tree, t_list **tokens)
{
	tree->category = TR_REDIRECT_HERE_DOC;
	*tokens = (*tokens)->next;
	tree->left = parse_word(tokens);
	tree->right = NULL;
}

t_tree	*parse_redirection(t_list **tokens)
{
	t_tree	*tree;
	t_token	*token;

	tree = null_guard(malloc(sizeof(t_tree)),
			PROGRAM_NAME, "parse_redirection().");
	if (*tokens == NULL)
		panic("parse_redirection()");
	token = (*tokens)->content;
	if (token->category == T_IN_REDIRECT)
		set_tree_to_redirect_in(tree, tokens);
	else if (token->category == T_OUT_REDIRECT)
		set_tree_to_redirect_out(tree, tokens);
	else if (token->category == T_APPEND_REDIRECT)
		set_tree_to_redirect_append(tree, tokens);
	else if (token->category == T_HERE_DOC)
		set_tree_to_here_doc(tree, tokens);
	else
		panic("parse_redirection()");
	return (tree);
}
