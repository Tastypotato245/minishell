/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_parameter_utils_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:07:26 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:07:30 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expansion_bonus.h>

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
