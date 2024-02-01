/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:57:47 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/30 20:30:22 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <kyusulib.h>
#include <readline/readline.h>
#include <ui.h>
#include <list.h>
#include <execute.h>
#include <tokenize.h>
#include <parse.h>
#include <traverse.h>

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_list	*tokens;
	t_tree	*tree;

	if (argc != 1 || argv == NULL)
		exit_handler(0, PROGRAM_NAME, "enter ./minishell");
	print_frankshell_image();
	if (DEBUG)
		printf(" *** DEBUG_MODE *** \t *** DEBUG_MODE *** \n");
	while (1)
	{
		line = readline("🍔 $ ");
		if (line == NULL)
			break ;
		else
		{
			tokens = tokenize(line);
			if (DEBUG)
				ft_lstiter(tokens, print_token);
			if (is_valid_tokens(tokens))
			{
				ft_lstclear(&tokens, destroy_token);
				free(line);
				continue;
			}
			tree = parse(tokens);
			if (tree == NULL)
			{
				ft_lstclear(&tokens, destroy_token);
				free(line);
				continue;
			}
			if (DEBUG)
				print_tree(tree, 0);
			traverse(tree, envp);
			destroy_tree(tree);
			ft_lstclear(&tokens, destroy_token);
			free(line);
		}
	}
	return (0);
}
