/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_simple_command_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:10:33 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:10:34 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse_bonus.h>
#include <tokenize_bonus.h>
#include <panic_bonus.h>

static t_tree	*set_tree_to_smpl_cmd_end(t_tree *tree)
{
	tree->category = TR_SMPL_CMD_END;
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

static	t_tree	*set_tree_to_smpl_cmd_continue(t_list **tokens, t_tree *tree)
{
	tree->category = TR_SMPL_CMD_CONTINUE;
	tree->right = parse_simple_command(tokens);
	if (tree->right == NULL)
		return (destroy_tree(tree));
	return (tree);
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
		return (set_tree_to_smpl_cmd_end(tree));
	token = (*tokens)->content;
	if (is_control_operator(token->category))
		return (set_tree_to_smpl_cmd_end(tree));
	else
		return (set_tree_to_smpl_cmd_continue(tokens, tree));
}
