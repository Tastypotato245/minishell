/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_quote_removal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:32:55 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/05 21:47:24 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expansion.h>
#include <vector.h>

static void	handling_quote(const char *line, size_t *i, t_vector *vector)
{
	const char	quote = line[*i];

	(*i)++;
	while (line[*i] != '\0' && line[*i] != quote)
	{
		push_back(vector, line[*i]);
		(*i)++;
	}
	(*i)++;
}

char	*quote_removal(char	*word)
{
	t_vector	vector;
	size_t		i;

	i = 0;
	init_vector(&vector);
	while (word[i] != '\0')
	{
		if (word[i] == '\"' || word[i] == '\'')
			handling_quote(word, &i, &vector);
		else
			push_back(&vector, word[i++]);
	}
	push_back(&vector, '\0');
	return (vector.data);
}
