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

t_list	*tokenize(char *line)
{
	const size_t	line_len = ft_strlen(line);
	t_list			*tokens;
	size_t			i;

	i = 0;
	while (i < line_len)
	{
		printf("%c\n", line[i]);
		i++;
	}
	tokens = NULL;
	return (tokens);
}
