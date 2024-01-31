/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:57:47 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/31 17:46:58 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <kyusulib.h>
#include <readline/readline.h>
#include <ui.h>
#include <list.h>
#include <dict.h>
#include <execute.h>
#include <tokenize.h>
#include <parse.h>
#include <traverse.h>

void	leak_checker(void)
{
	system("leaks minishell");
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_list	*tokens;
	t_tree	*tree;
	t_dict	*env_dict;

	atexit(leak_checker);
	if (argc != 1 || argv == NULL)
		exit_handler(0, PROGRAM_NAME, "enter ./minishell");
	print_symbol();
	env_dict = to_dict(envp);
	//builtin_env(env_dict);
	print_dict(env_dict);
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
			tree = parse(tokens);
			if (DEBUG)
				print_tree(tree, 0);
			traverse(tree, envp);
			free(line);
		}
	}
	free_dict(env_dict);
	return (0);
}
