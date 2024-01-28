/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_categorize_token.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:04:25 by younghoc          #+#    #+#             */
/*   Updated: 2024/01/28 14:04:27 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenize.h>

t_token *categorize_pipe(const char *line, size_t *i)
{
}

t_token *categorize_less_than(const char *line, size_t *i)
{
}

t_token *categorize_greater_than(const char *line, size_t *i)
{
}

t_token	*categorize_token(const char *line, size_t *i)
{
	if (line[*i] == '|')
		return (categorize_pipe(line, i));
	if (line[*i] == '&')
		return (create_and_token(line, i));
	if (line[*i] == '(')
		return (create_lparen_token(line, i));
	if (line[*i] == ')')
		return (create_rparen_token(line, i));
	if (line[*i] == '<')
		return (categorize_less_than(line, i));
	if (line[*i] == '>')
		return (categorize_greater_than(line, i));
	return (create_word_token(line, i));
}
