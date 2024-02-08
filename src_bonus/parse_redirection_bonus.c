/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirection_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:10:23 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:10:24 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse_bonus.h>
#include <tokenize_bonus.h>
#include <panic_bonus.h>

static void	set_tree_to_redirect_in(t_list **tokens, t_tree *tree)
{
	tree->category = TR_REDIRECT_IN;
	*tokens = (*tokens)->next;
	tree->left = parse_word(tokens);
}

static void	set_tree_to_redirect_out(t_list **tokens, t_tree *tree)
{
	tree->category = TR_REDIRECT_OUT;
	*tokens = (*tokens)->next;
	tree->left = parse_word(tokens);
}

static void	set_tree_to_redirect_append(t_list **tokens, t_tree *tree)
{
	tree->category = TR_REDIRECT_APPEND;
	*tokens = (*tokens)->next;
	tree->left = parse_word(tokens);
}

static void	set_tree_to_here_doc(t_list **tokens, t_tree *tree)
{
	tree->category = TR_REDIRECT_HERE_DOC;
	*tokens = (*tokens)->next;
	tree->left = parse_word(tokens);
}

t_tree	*parse_redirection(t_list **tokens)
{
	t_tree	*tree;
	t_token	*token;

	tree = null_guard(ft_calloc(1, sizeof(t_tree)),
			PROGRAM_NAME, "parse_redirection().");
	if (*tokens == NULL)
		panic("parse_redirection()");
	token = (*tokens)->content;
	if (token->category == T_IN_REDIRECT)
		set_tree_to_redirect_in(tokens, tree);
	else if (token->category == T_OUT_REDIRECT)
		set_tree_to_redirect_out(tokens, tree);
	else if (token->category == T_APPEND_REDIRECT)
		set_tree_to_redirect_append(tokens, tree);
	else if (token->category == T_HERE_DOC)
		set_tree_to_here_doc(tokens, tree);
	else
		panic("parse_redirection()");
	if (tree->left == NULL)
		return (destroy_tree(tree));
	return (tree);
}
