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

static int	handling_quote(const char *line, size_t *i, t_vector *vector)
{
	const char	quote = line[*i];

	push_back(vector, line[*i]);
	(*i)++;
	while (line[*i] != '\0' && line[*i] != quote)
	{
		push_back(vector, line[*i]);
		(*i)++;
	}
	if (line[*i] == '\0')
		return (-1);
	push_back(vector, line[*i]);
	(*i)++;
	return (0);
}

t_token	*create_word_token(const char *line, size_t *i)
{
	t_token		*token;
	t_vector	vector;
	int			ret;

	token = null_guard(malloc(sizeof(t_token)),
			PROGRAM_NAME, "create_word_token().");
	token->category = T_WORD;
	token->content = NULL;
	init_vector(&vector);
	while (line[*i] != '\0' && ft_is_metacharacter(line[*i]) == 0)
	{
		if (line[*i] == '\"' || line[*i] == '\'')
		{
			ret = handling_quote(line, i, &vector);
			if (ret == -1)
			{
				destroy_vector(&vector);
				destroy_token(token);
				return (create_error_token());
			}
		}
		else
		{
			push_back(&vector, line[*i]);
			(*i)++;
		}
	}
	push_back(&vector, '\0');
	token->content = vector.data;
	return (token);
}

t_token	*create_error_token(void)
{
	t_token	*token;

	token = null_guard(malloc(sizeof(t_token)),
			PROGRAM_NAME, "create_error_token().");
	token->category = T_ERROR;
	token->content = NULL;
	return (token);
}
