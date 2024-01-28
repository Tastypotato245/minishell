/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:56:55 by younghoc          #+#    #+#             */
/*   Updated: 2024/01/28 12:56:57 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenize.h>

static int	ft_is_space(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	return (0);
}

t_list	*tokenize(const char *line)
{
	const size_t	line_len = ft_strlen(line);
	t_list			*tokens;
	t_list			*token;
	size_t			i;

	i = 0;
	while (i < line_len)
	{
		if (ft_is_space(line[i]))
		{
			i++;
			continue ;
		}
		token = categorize_token(line, &i);
		ft_lstadd_back(&tokens, token);
		i++;
	}
	tokens = NULL;
	return (tokens);
}
