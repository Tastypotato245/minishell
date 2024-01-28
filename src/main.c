/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:57:47 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/26 19:58:31 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <tokenize.h>

int	main(void)
{
	char	*line;
	t_list	*tokens;

	while (1)
	{
		line = readline("minishell > ");
		tokens = tokenize(line);
		ft_lstiter(tokens, print_token);
		free(line);
	}
	return (0);
}
