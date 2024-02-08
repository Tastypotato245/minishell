/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_quote_removal_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:07:34 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:07:39 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expansion_bonus.h>
#include <vector_bonus.h>

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
		if (word[i] == '\"' || word[i] == '\'' || word[i] == '\a')
			handling_quote(word, &i, &vector);
		else
			push_back(&vector, word[i++]);
	}
	push_back(&vector, '\0');
	return (vector.data);
}
