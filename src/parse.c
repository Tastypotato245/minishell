/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:39:56 by younghoc          #+#    #+#             */
/*   Updated: 2024/01/30 19:54:25 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <tokenize.h>
#include <panic.h>

t_tree	*parse_word(t_list **tokens)
{
	t_tree	*tree;
	t_token	*token;

	tree = null_guard(malloc(sizeof(t_tree)),
			PROGRAM_NAME, "parse_word().");
	if (*tokens == NULL)
		panic("parse_word()");
	token = (*tokens)->content;
	if (token->category != T_WORD)
		panic("parse_word()");
	tree->category = TR_WORD;
	tree->left = token->content;
	tree->right = NULL;
	*tokens = (*tokens)->next;
	return (tree);
}

t_tree	*parse_simple_command(t_list **tokens)
{
	t_tree	*tree;
	t_token	*token;

	tree = null_guard(malloc(sizeof(t_tree)),
			PROGRAM_NAME, "parse_simple_command().");
	if (*tokens == NULL)
		panic("parse_pipeline()");
	token = (*tokens)->content;
	if (token->category == T_IN_REDIRECT
		|| token->category == T_OUT_REDIRECT
		|| token->category == T_APPEND_REDIRECT
		|| token->category == T_HERE_DOC)
		tree->left = parse_redirection(tokens);
	else
		tree->left = parse_word(tokens);
	if (*tokens == NULL)
	{
		tree->category = TR_SMPL_CMD_END;
		tree->right = NULL;
		return (tree);
	}
	token = (*tokens)->content;
	if (token->category == T_AND
		|| token->category == T_OR
		|| token->category == T_PIPE
		|| token->category == T_L_PAREN
		|| token->category == T_R_PAREN)
	{
		tree->category = TR_SMPL_CMD_END;
		tree->right = NULL;
		return (tree);
	}
	else
	{
		tree->category = TR_SMPL_CMD_CONTINUE;
		tree->right = parse_simple_command(tokens);
		return (tree);
	}
}

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

t_tree	*parse(t_list *tokens)
{
	t_tree	*tree;

	if (tokens == NULL)
		return (NULL);
	tree = parse_list(&tokens);
	if (tokens != NULL)
		panic("parse(): left token");
	return (tree);
}
