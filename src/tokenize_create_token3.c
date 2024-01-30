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
