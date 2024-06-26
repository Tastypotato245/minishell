/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_categorize_token_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:12:40 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:12:44 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenize_bonus.h>

static t_token	*categorize_pipe(const char *line, size_t *i)
{
	(*i)++;
	if (line[*i] == '|')
		return (create_or_token(i));
	return (create_pipe_token());
}

static t_token	*categorize_ampersand(const char *line, size_t *i)
{
	(*i)++;
	if (line[*i] == '&')
		return (create_and_token(i));
	return (create_error_token());
}

static t_token	*categorize_less_than(const char *line, size_t *i)
{
	(*i)++;
	if (line[*i] == '<')
		return (create_here_doc_token(i));
	return (create_in_redirect_token());
}

static t_token	*categorize_greater_than(const char *line, size_t *i)
{
	(*i)++;
	if (line[*i] == '>')
		return (create_append_redirect_token(i));
	return (create_out_redirect_token());
}

t_token	*categorize_token(const char *line, size_t *i)
{
	if (line[*i] == '|')
		return (categorize_pipe(line, i));
	if (line[*i] == '&')
		return (categorize_ampersand(line, i));
	if (line[*i] == '(')
		return (create_lparen_token(i));
	if (line[*i] == ')')
		return (create_rparen_token(i));
	if (line[*i] == '<')
		return (categorize_less_than(line, i));
	if (line[*i] == '>')
		return (categorize_greater_than(line, i));
	return (create_word_token(line, i));
}
