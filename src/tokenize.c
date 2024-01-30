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

t_list	*tokenize(const char *line)
{
	const size_t	line_len = ft_strlen(line);
	t_list			*tokens;
	t_token			*token;
	t_list			*token_element;
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
		token_element = ft_lstnew(token);
		ft_lstadd_back(&tokens, token_element);
	}
	return (tokens);
}
