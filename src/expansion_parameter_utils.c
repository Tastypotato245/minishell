/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_parameter_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:49:47 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/06 17:49:48 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expansion.h>

int	check_valid_dollar(const char *word)
{
	int		in_single_quotes;
	int		in_double_quotes;
	size_t	i;

	in_single_quotes = 0;
	in_double_quotes = 0;
	i = 0;
	while (word[i] != '\0')
	{
		if (word[i] == '\'' && !in_double_quotes)
			in_single_quotes = !in_single_quotes;
		else if (word[i] == '\"' && !in_single_quotes)
			in_double_quotes = !in_double_quotes;
		if (word[i] == '$' && !in_double_quotes && !in_single_quotes)
			return (1);
		i++;
	}
	return (0);
}
