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
