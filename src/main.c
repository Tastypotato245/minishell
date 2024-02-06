/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:57:47 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/05 20:46:34 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <kyusulib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <ui.h>
#include <list.h>
#include <dict.h>
#include <execute.h>
#include <tokenize.h>
#include <parse.h>
#include <here_document.h>
#include <traverse.h>
#include <signal_handler.h>


void	init_frankshell(t_dict *env_dict)
{
	print_symbol();
	dict_modi_val_or_new_in_sort(env_dict, "OLDPWD", NULL);
	dict_modi_val_or_new_in_sort(env_dict, ft_strdup("?"), ft_itoa(0));
	set_signal();
	rl_catch_signals = 0;
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_list	*tokens;
	t_tree	*tree;
	t_dict	*env_dict;
	t_list	*here_doc_list;

	if (argc != 1 || argv == NULL)
		exit_handler(0, PROGRAM_NAME, "enter ./minishell");
	here_doc_list = NULL;
	env_dict = to_dict(envp);
	init_frankshell(env_dict);
	while (1)
	{
		line = readline("$ ");
		if (line == NULL)
			cntl_d(env_dict);
		else
		{
			tokens = tokenize(line);
			if (DEBUG)
				ft_lstiter(tokens, print_token);
			if (is_valid_tokens(tokens))
			{
				ft_lstclear(&tokens, destroy_token);
				free(line);
				continue ;
			}
			tree = parse(tokens);
			if (tree == NULL)
			{
				ft_lstclear(&tokens, destroy_token);
				free(line);
				continue ;
			}
			if (DEBUG)
				print_tree(tree, 0);
			add_history(line);
			if (here_doc_traverse(tree, &here_doc_list))
			{
				unlink_here_doc_temp_file(&here_doc_list);
				destroy_tree(tree);
				ft_lstclear(&tokens, destroy_token);
				free(line);
				continue ;
			}
			traverse(tree, env_dict);
			unlink_here_doc_temp_file(&here_doc_list);
			destroy_tree(tree);
			ft_lstclear(&tokens, destroy_token);
			free(line);
		}
	}
	free_dict(env_dict);
	rl_clear_history();
//	clear_history();
	return (0);
}
