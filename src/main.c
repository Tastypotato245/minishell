/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:57:47 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 12:03:26 by kyusulee         ###   ########.fr       */
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

int	g_signal;

static void	init_frankshell(t_dict **env_dict, char **envp)
{
	print_symbol();
	*env_dict = to_dict(envp);
	set_signal(0);
	rl_catch_signals = 0;
	if (find_pair_in_dict(*env_dict, "OLDPWD") == NULL)
		dict_modi_val_or_new(*env_dict, ft_strdup("OLDPWD"), NULL);
	if (find_pair_in_dict(*env_dict, "?") == NULL)
		dict_modi_val_or_new(*env_dict, ft_strdup("?"), ft_itoa(0));
	if (find_pair_in_dict(*env_dict, "PATH") == NULL)
		dict_modi_val_or_new(*env_dict, ft_strdup("PATH"), \
				ft_strdup(DEFAULT_PATH));
}

static int	free_tokens_and_line(t_list **tokens, char *line)
{
	ft_lstclear(tokens, destroy_token);
	free(line);
	return (-1);
}

static int	frontend(t_dict *env_dict, t_list **tokens,
		t_tree **tree, char *line)
{
	*tokens = tokenize(line);
	if (is_valid_tokens(*tokens))
	{
		dict_modi_val_or_new(env_dict, "?", ft_itoa(2));
		add_history(line);
		return (free_tokens_and_line(tokens, line));
	}
	if (DEBUG)
		ft_lstiter(*tokens, print_token);
	if (ft_lstsize(*tokens) == 0)
		return (free_tokens_and_line(tokens, line));
	*tree = parse(*tokens);
	if (*tree == NULL)
	{
		dict_modi_val_or_new(env_dict, "?", ft_itoa(2));
		add_history(line);
		return (free_tokens_and_line(tokens, line));
	}
	if (DEBUG)
		print_tree(*tree, 0);
	return (0);
}

static void	backend(t_tree *tree, t_dict *env_dict, char *line, t_list **tokens)
{
	t_list	*here_doc_list;

	if (g_signal == 1 && dict_modi_val_or_new(env_dict, "?", ft_itoa(1)))
		g_signal = 0;
	here_doc_list = NULL;
	if (!here_doc_traverse(tree, &here_doc_list, env_dict))
		traverse(tree, env_dict);
	unlink_here_doc_temp_file(&here_doc_list);
	destroy_tree(tree);
	ft_lstclear(tokens, destroy_token);
	free(line);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_list	*tokens;
	t_tree	*tree;
	t_dict	*env_dict;

	if (argc != 1 || argv == NULL)
		exit_handler(0, PROGRAM_NAME, "enter ./minishell");
	init_frankshell(&env_dict, envp);
	while (1)
	{
		line = readline("$ ");
		if (line == NULL)
			cntl_d(env_dict);
		else
		{
			if (frontend(env_dict, &tokens, &tree, line))
				continue ;
			add_history(line);
			backend(tree, env_dict, line, &tokens);
		}
	}
	free_dict(env_dict);
	rl_clear_history();
	return (0);
}
