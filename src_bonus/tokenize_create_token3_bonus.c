/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_create_token3_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:13:22 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:13:27 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_bonus.h>
#include <tokenize_bonus.h>
#include <vector_bonus.h>

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

static int	read_characters(const char *line, size_t *i, t_vector *vector)
{
	int	ret;

	while (line[*i] != '\0' && ft_is_metacharacter(line[*i]) == 0)
	{
		if (line[*i] == '\"' || line[*i] == '\'')
		{
			ret = handling_quote(line, i, vector);
			if (ret == -1)
				return (-1);
		}
		else
			push_back(vector, line[(*i)++]);
	}
	return (0);
}

t_token	*create_word_token(const char *line, size_t *i)
{
	t_token		*token;
	t_vector	vector;

	token = null_guard(malloc(sizeof(t_token)),
			PROGRAM_NAME, "create_word_token().");
	token->category = T_WORD;
	token->content = NULL;
	init_vector(&vector);
	if (read_characters(line, i, &vector) == -1)
	{
		destroy_vector(&vector);
		destroy_token(token);
		return (create_error_token());
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
