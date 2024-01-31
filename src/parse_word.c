/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:32:58 by younghoc          #+#    #+#             */
/*   Updated: 2024/01/31 14:32:59 by younghoc         ###   ########.fr       */
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
		return (print_parse_error(*tokens, tree));
	token = (*tokens)->content;
	if (token->category != T_WORD)
		return (print_parse_error(*tokens, tree));
	tree->category = TR_WORD;
	tree->left = token->content;
	tree->right = NULL;
	*tokens = (*tokens)->next;
	return (tree);
}
