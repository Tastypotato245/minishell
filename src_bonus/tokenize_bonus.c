/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:12:28 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:12:36 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_bonus.h>
#include <tokenize_bonus.h>

t_list	*tokenize(const char *line)
{
	const size_t	line_len = ft_strlen(line);
	t_list			*tokens;
	t_token			*token;
	t_list			*token_element;
	size_t			i;

	i = 0;
	tokens = NULL;
	while (i < line_len)
	{
		if (ft_is_space(line[i]))
		{
			i++;
			continue ;
		}
		token = categorize_token(line, &i);
		token_element = ft_lstnew(token);
		null_guard(token_element, PROGRAM_NAME, "tokenize().");
		ft_lstadd_back(&tokens, token_element);
	}
	return (tokens);
}
