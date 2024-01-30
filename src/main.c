/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:57:47 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/30 19:50:46 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kyusulib.h>
#include <readline/readline.h>
#include <execute.h>
#include <list.h>
#include <parse.h>
#include <tokenize.h>
#include <traverse.h>
#include <ui.h>

int main(int argc, char **argv, char **envp) {
	char *line;
	t_list *tokens;
	t_tree *tree;

	if (argc != 1 || (argc == 2 && ft_strncmp(argv[1], "debug", 5) != 0))
		exit_handler(0, PROGRAM_NAME, "enter ./minishell");
	print_frankshell_image();
	while (1) {
		line = readline("🍔 $ ");
		if (line == NULL)
			break;
		if (ft_strncmp(line, "test", 4) == 0)
			execute_test(envp);
		else {
			tokens = tokenize(line);
			ft_lstiter(tokens, print_token);
			tree = parse(tokens);
			print_tree(tree, 0);
			traverse(tree, envp);
			free(line);
		}
	}
	return (0);
}
