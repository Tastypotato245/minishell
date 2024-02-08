/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_create_token1_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:13:03 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:13:09 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_bonus.h>
#include <tokenize_bonus.h>
#include <vector_bonus.h>

t_token	*create_or_token(size_t *i)
{
	t_token	*token;

	token = null_guard(malloc(sizeof(t_token)),
			PROGRAM_NAME, "create_or_token().");
	token->category = T_OR;
	token->content = NULL;
	(*i)++;
	return (token);
}

t_token	*create_and_token(size_t *i)
{
	t_token	*token;

	token = null_guard(malloc(sizeof(t_token)),
			PROGRAM_NAME, "create_and_token().");
	token->category = T_AND;
	token->content = NULL;
	(*i)++;
	return (token);
}

t_token	*create_pipe_token(void)
{
	t_token	*token;

	token = null_guard(malloc(sizeof(t_token)),
			PROGRAM_NAME, "create_pipe_token().");
	token->category = T_PIPE;
	token->content = NULL;
	return (token);
}

t_token	*create_lparen_token(size_t *i)
{
	t_token	*token;

	token = null_guard(malloc(sizeof(t_token)),
			PROGRAM_NAME, "create_lparen_token().");
	token->category = T_L_PAREN;
	token->content = NULL;
	(*i)++;
	return (token);
}

t_token	*create_rparen_token(size_t *i)
{
	t_token	*token;

	token = null_guard(malloc(sizeof(t_token)),
			PROGRAM_NAME, "create_rparen_token().");
	token->category = T_R_PAREN;
	token->content = NULL;
	(*i)++;
	return (token);
}
