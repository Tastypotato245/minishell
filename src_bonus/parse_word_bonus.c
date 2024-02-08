/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:10:42 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:10:43 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse_bonus.h>
#include <tokenize_bonus.h>
#include <panic_bonus.h>

t_tree	*parse_word(t_list **tokens)
{
	t_tree	*tree;
	t_token	*token;

	tree = null_guard(ft_calloc(1, sizeof(t_tree)),
			PROGRAM_NAME, "parse_word().");
	if (*tokens == NULL)
		return (print_parse_error(*tokens, tree));
	token = (*tokens)->content;
	if (token->category != T_WORD)
		return (print_parse_error(*tokens, tree));
	tree->category = TR_WORD;
	tree->left = ft_strdup(token->content);
	*tokens = (*tokens)->next;
	return (tree);
}
