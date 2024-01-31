/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:04:37 by younghoc          #+#    #+#             */
/*   Updated: 2024/01/28 16:04:38 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenize.h>

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
	const t_token	*token = content;

	free(token->content);
}
