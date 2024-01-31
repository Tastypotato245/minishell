/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_simple_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:31:02 by younghoc          #+#    #+#             */
/*   Updated: 2024/01/31 14:31:03 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <tokenize.h>
#include <panic.h>

static t_tree	*parse_smpl_cmd_end(t_tree *tree)
{
	tree->category = TR_SMPL_CMD_END;
	tree->right = NULL;
	return (tree);
}

static int	is_redirect_or_here_doc(t_token_category category)
{
	if (category == T_IN_REDIRECT
		|| category == T_OUT_REDIRECT
		|| category == T_APPEND_REDIRECT
		|| category == T_HERE_DOC)
		return (1);
	return (0);
}

static int	is_control_operator(t_token_category category)
{
	if (category == T_AND
		|| category == T_OR
		|| category == T_PIPE
		|| category == T_L_PAREN
		|| category == T_R_PAREN)
		return (1);
	return (0);
}

t_tree	*parse_simple_command(t_list **tokens)
{
	t_tree	*tree;
	t_token	*token;

	tree = null_guard(ft_calloc(1, sizeof(t_tree)),
			PROGRAM_NAME, "parse_simple_command().");
	if (*tokens == NULL)
		panic("parse_pipeline()");
	token = (*tokens)->content;
	if (is_redirect_or_here_doc(token->category))
		tree->left = parse_redirection(tokens);
	else
		tree->left = parse_word(tokens);
	if (tree->left == NULL)
		return (destroy_tree(tree));
	if (*tokens == NULL)
		return (parse_smpl_cmd_end(tree));
	token = (*tokens)->content;
	if (is_control_operator(token->category))
		return (parse_smpl_cmd_end(tree));
	else
	{
		tree->category = TR_SMPL_CMD_CONTINUE;
		tree->right = parse_simple_command(tokens);
		if (*tokens == NULL)
			return (parse_smpl_cmd_end(tree));
		return (tree);
	}
}
