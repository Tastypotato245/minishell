/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_create_token2_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:13:18 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:13:19 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_bonus.h>
#include <tokenize_bonus.h>
#include <vector_bonus.h>

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
