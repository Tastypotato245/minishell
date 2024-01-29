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
#include <parse.h>

int	main(void)
{
	char	*line;
	t_list	*tokens;
	t_tree	*tree;

	while (1)
	{
		line = readline("🍔 $ ");
		if (line == NULL)
			break ;
		tokens = tokenize(line);
		ft_lstiter(tokens, print_token);
		tree = parse(tokens);
		print_tree(tree, 0);
		free(line);
	}
	return (0);
}
