/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_create_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:03:40 by younghoc          #+#    #+#             */
/*   Updated: 2024/01/28 14:03:42 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenize.h>
#include <vector.h>

t_token	*create_in_redirect_token(void)
{
	t_token	*token;

	token = null_guard(malloc(sizeof(t_token)),
			PROGRAM_NAME, "create_in_redirect_token().");
	token->category = T_IN_REDIRECT;
	token->content = NULL;
	return (token);
}

t_token	*create_out_redirect_token(void)
{
	t_token	*token;

	token = null_guard(malloc(sizeof(t_token)),
			PROGRAM_NAME, "create_out_redirect_token().");
	token->category = T_OUT_REDIRECT;
	token->content = NULL;
	return (token);
}

t_token	*create_append_redirect_token(size_t *i)
{
	t_token	*token;

	token = null_guard(malloc(sizeof(t_token)),
			PROGRAM_NAME, "create_append_redirect_token().");
	token->category = T_APPEND_REDIRECT;
	token->content = NULL;
	(*i)++;
	return (token);
}

t_token	*create_here_doc_token(size_t *i)
{
	t_token	*token;

	token = null_guard(malloc(sizeof(t_token)),
			PROGRAM_NAME, "create_here_doc_token().");
	token->category = T_HERE_DOC;
	token->content = NULL;
	(*i)++;
	return (token);
}
