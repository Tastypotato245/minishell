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

t_token	*create_or_token(size_t *i)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	token->category = T_OR;
	token->content = NULL;
	i++;
	return (token);
}

t_token	*create_and_token(size_t *i)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	token->category = T_AND;
	token->content = NULL;
	i++;
	return (token);
}

t_token	*create_pipe_token()
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	token->category = T_PIPE;
	token->content = NULL;
	return (token);
}

t_token	*create_lparen_token(size_t *i)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	token->category = T_L_PAREN;
	token->content = NULL;
	i++;
	return (token);
}

t_token	*create_rparen_token(size_t *i)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	token->category = T_R_PAREN;
	token->content = NULL;
	i++;
	return (token);
}

t_token	*create_in_redirect_token()
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	token->category = T_IN_REDIRECT;
	token->content = NULL;
	return (token);
}

t_token	*create_out_redirect_token()
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	token->category = T_OUT_REDIRECT;
	token->content = NULL;
	return (token);
}

t_token	*create_append_redirect_token(size_t *i)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	token->category = T_APPEND_REDIRECT;
	token->content = NULL;
	i++;
	return (token);
}

t_token	*create_here_doc_token(size_t *i)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	token->category = T_HERE_DOC;
	token->content = NULL;
	i++;
	return (token);
}

t_token	*create_word_token(const char *line, size_t *i)
{
	(void)line;
	(void)i;
	return (create_error_token());
}

t_token	*create_error_token()
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	token->category = T_ERROR;
	token->content = NULL;
	return (token);
}
