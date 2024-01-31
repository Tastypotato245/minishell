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
	if (tree->left == NULL)
	{
		tree->left = destroy_tree(tree);
		return ;
	}
	if (*tokens == NULL)
	{
		tree->left = print_parse_error(*tokens, tree);
		return ;
	}
	token = (*tokens)->content;
	if (token->category != T_R_PAREN)
	{
		panic("parse_paren()");
		return ;
	}
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
	if (tree->right == NULL)
		return (destroy_tree(tree));
	return (tree);
}

t_tree	*parse_pipeline(t_list **tokens)
{
	t_tree	*tree;
	t_token	*token;

	tree = null_guard(ft_calloc(1, sizeof(t_tree)),
			PROGRAM_NAME, "parse_pipeline().");
	if (*tokens == NULL)
		return (print_parse_error(*tokens, tree));
	token = (*tokens)->content;
	if (token->category == T_L_PAREN)
		parse_paren(tokens, tree, token);
	else
		tree->left = parse_simple_command(tokens);
	if (tree->left == NULL)
		return (destroy_tree(tree));
	if (*tokens == NULL)
		return (set_tree_to_pipe_end(tree));
	token = (*tokens)->content;
	if (token->category == T_PIPE)
		return (parse_pipe_continue(tree, tokens));
	return (set_tree_to_pipe_end(tree));
}
