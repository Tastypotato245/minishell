/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipeline_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:10:05 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:10:05 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse_bonus.h>
#include <tokenize_bonus.h>
#include <panic_bonus.h>

static int	parse_paren(t_list **tokens, t_tree *tree, t_token *token)
{
	*tokens = (*tokens)->next;
	tree->left = parse_list(tokens);
	if (tree->left == NULL)
	{
		destroy_tree(tree);
		return (-1);
	}
	if (*tokens == NULL)
	{
		print_parse_error(*tokens, tree);
		return (-1);
	}
	token = (*tokens)->content;
	if (token->category != T_R_PAREN)
		panic("parse_paren()");
	*tokens = (*tokens)->next;
	if (*tokens == NULL)
		return (0);
	token = (*tokens)->content;
	if (token->category == T_PIPE)
	{
		print_parse_error(*tokens, tree);
		return (-1);
	}
	return (0);
}

static t_tree	*set_tree_to_pipe_end(t_tree *tree)
{
	tree->category = TR_PIPE_END;
	tree->right = NULL;
	return (tree);
}

static t_tree	*parse_pipe_continue(t_tree *tree, t_list **tokens)
{
	t_token	*token;

	tree->category = TR_PIPE_CONTINUE;
	*tokens = (*tokens)->next;
	if (*tokens == NULL)
		return (print_parse_error(*tokens, tree));
	token = (*tokens)->content;
	if (token->category == T_L_PAREN)
		return (print_parse_error(*tokens, tree));
	tree->right = parse_pipeline(tokens);
	if (tree->right == NULL)
		return (destroy_tree(tree));
	return (tree);
}

t_tree	*parse_pipeline(t_list **tokens)
{
	t_tree	*tree;
	t_token	*token;
	int		ret;

	tree = null_guard(ft_calloc(1, sizeof(t_tree)),
			PROGRAM_NAME, "parse_pipeline().");
	if (*tokens == NULL)
		return (print_parse_error(*tokens, tree));
	token = (*tokens)->content;
	ret = 0;
	if (token->category == T_L_PAREN)
		ret = parse_paren(tokens, tree, token);
	else
		tree->left = parse_simple_command(tokens);
	if (ret == -1)
		return (NULL);
	else if (tree->left == NULL)
		return (destroy_tree(tree));
	if (*tokens == NULL)
		return (set_tree_to_pipe_end(tree));
	token = (*tokens)->content;
	if (token->category == T_PIPE)
		return (parse_pipe_continue(tree, tokens));
	return (set_tree_to_pipe_end(tree));
}
