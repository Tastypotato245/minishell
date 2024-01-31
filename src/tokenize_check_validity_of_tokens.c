/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_check_validity_of_tokens.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:22:43 by younghoc          #+#    #+#             */
/*   Updated: 2024/01/31 15:22:45 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenize.h>

static int	is_error_token(t_token *token)
{
	if (token->category == T_ERROR)
		return (1);
	return (0);
}

int	is_valid_tokens(t_list *tokens)
{
	while (tokens)
	{
		if (is_error_token(tokens->content))
			return (-1);
		tokens = tokens->next;
	}
	return (0);
}
