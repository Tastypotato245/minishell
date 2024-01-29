/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:39:56 by younghoc          #+#    #+#             */
/*   Updated: 2024/01/29 13:40:03 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <tokenize.h>
#include <panic.h>

t_tree	*parse_word(t_list **tokens)
{
	t_tree	*tree;
	t_token	*token;

	tree = malloc(sizeof(t_tree));
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

t_tree	*parse_redirection(t_list **tokens)
{
	t_tree	*tree;
	t_token	*token;

	tree = malloc(sizeof(t_tree));
	if (*tokens == NULL)
		panic("parse_redirection()");
	token = (*tokens)->content;
	if (token->category == T_IN_REDIRECT)
	{
		tree->category = TR_REDIRECT_IN;
		*tokens = (*tokens)->next;
		tree->left = parse_word(tokens);
		tree->right = NULL;
	}
	else if (token->category == T_OUT_REDIRECT)
	{
		tree->category = TR_REDIRECT_OUT;
		*tokens = (*tokens)->next;
		tree->left = parse_word(tokens);
		tree->right = NULL;
	}
	else if (token->category == T_APPEND_REDIRECT)
	{
		tree->category = TR_REDIRECT_APPEND;
		*tokens = (*tokens)->next;
		tree->left = parse_word(tokens);
		tree->right = NULL;
	}
	else if (token->category == T_HERE_DOC)
	{
		tree->category = TR_REDIRECT_HERE_DOC;
		*tokens = (*tokens)->next;
		tree->left = parse_word(tokens);
		tree->right = NULL;
	}
	else
		panic("parse_redirection()");
	return (tree);
}

t_tree	*parse_simple_command(t_list **tokens)
{
	t_tree	*tree;
	t_token	*token;

	tree = malloc(sizeof(t_tree));
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
		|| token->category == T_R_PAREN){
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

t_tree	*parse_pipeline(t_list **tokens)
{
	t_tree	*tree;
	t_token	*token;

	tree = malloc(sizeof(t_tree));
	if (*tokens == NULL)
		panic("parse_pipeline()");
	token = (*tokens)->content;
	if (token->category == T_L_PAREN)
	{
		*tokens = (*tokens)->next;
		tree->left = parse_list(tokens);
	}
	else
		tree->left = parse_simple_command(tokens);
	if (*tokens == NULL)
	{
		tree->category = TR_PIPE_END;
		tree->right = NULL;
		return (tree);
	}
	token = (*tokens)->content;
	if (token->category == T_PIPE)
	{
		tree->category = TR_PIPE_CONTINUE;
		*tokens = (*tokens)->next;
		tree->right = parse_pipeline(tokens);
		return (tree);
	}
	else
	{
		tree->category = TR_PIPE_END;
		tree->right = NULL;
		return (tree);
	}
	return (tree);
}

t_tree	*parse_list(t_list **tokens)
{
	t_tree	*tree;
	t_token	*token;
	
	tree = malloc(sizeof(t_tree));
	tree->left = parse_pipeline(tokens);
	tree->right = NULL;
	if (*tokens == NULL)
	{
		tree->category = TR_LIST_END;
		tree->right = NULL;
		return (tree);
	}
	token = (*tokens)->content;
	if (token->category == T_AND)
	{
		tree->category = TR_LIST_AND;
		*tokens = (*tokens)->next;
		tree->right = parse_list(tokens);
		return (tree);
	}
	else if (token->category == T_OR)
	{
		tree->category = TR_LIST_OR;
		*tokens = (*tokens)->next;
		tree->right = parse_list(tokens);
		return (tree);
	}
	panic("parse_list()");
	return (tree);
}

t_tree	*parse(t_list *tokens)
{
	return (parse_list(&tokens));
}
