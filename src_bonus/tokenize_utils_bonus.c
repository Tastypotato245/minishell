/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:13:46 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:13:46 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenize_bonus.h>

int	ft_is_space(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	return (0);
}

int	ft_is_metacharacter(char c)
{
	if (c == '|')
		return (1);
	if (c == '&')
		return (1);
	if (c == '(')
		return (1);
	if (c == ')')
		return (1);
	if (c == '<')
		return (1);
	if (c == '>')
		return (1);
	if (ft_is_space(c))
		return (1);
	return (0);
}

void	destroy_token(void *content)
{
	t_token	*token;

	token = content;
	free(token->content);
	free(token);
}
