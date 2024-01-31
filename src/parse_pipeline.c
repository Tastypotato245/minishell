/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:28:31 by younghoc          #+#    #+#             */
/*   Updated: 2024/01/31 14:28:33 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <tokenize.h>
#include <panic.h>

static void	parse_paren(t_list **tokens, t_tree *tree, t_token *token)
{
	*tokens = (*tokens)->next;
	tree->left = parse_list(tokens);
	if (*tokens == NULL)
		panic("parse_pipeline(): rparen not found");
	token = (*tokens)->content;
	if (token->category != T_R_PAREN)
		panic("parse_pipeline(): rparen not found");
	*tokens = (*tokens)->next;
}

static t_tree	*set_tree_to_pipe_end(t_tree *tree)
{
	tree->category = TR_PIPE_END;
	tree->right = NULL;
	return (tree);
}

static t_tree	*parse_pipe_continue(t_tree *tree, t_list **tokens)
{
	tree->category = TR_PIPE_CONTINUE;
	*tokens = (*tokens)->next;
	tree->right = parse_pipeline(tokens);
	return (tree);
}

t_tree	*parse_pipeline(t_list **tokens)
{
	t_tree	*tree;
	t_token	*token;

	tree = null_guard(malloc(sizeof(t_tree)),
			PROGRAM_NAME, "parse_pipeline().");
	if (*tokens == NULL)
		panic("parse_pipeline()");
	token = (*tokens)->content;
	if (token->category == T_L_PAREN)
		parse_paren(tokens, tree, token);
	else
		tree->left = parse_simple_command(tokens);
	if (*tokens == NULL)
		return (set_tree_to_pipe_end(tree));
	token = (*tokens)->content;
	if (token->category == T_PIPE)
		return (parse_pipe_continue(tree, tokens));
	return (set_tree_to_pipe_end(tree));
}