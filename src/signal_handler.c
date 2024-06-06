/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:34:44 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/07 16:18:44 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <signal.h>
#include <dict.h>
#include <stdio.h>
#include <readline/readline.h>
#include <kyusulib.h>

static void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		//rl_replace_line("", 1);
		rl_redisplay();
		g_signal = 1;
	}
}

static void	signal_handler_for_heredoc(int sig)
{
	(void)sig;
	func_guard(close(0), PROGRAM_NAME, "signal_handler_for_heredoc().");
	g_signal = 1;
}

// 0 = default
// 1 = heredoc
// 2 = exec_parant
// 3 = exec_child
void	set_signal(int mod)
{
	if (mod == 0)
	{
		signal(SIGINT, signal_handler);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (mod == 1)
	{
		signal(SIGINT, signal_handler_for_heredoc);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (mod == 2)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (mod == 3)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
}

void	cntl_d(t_dict *env)
{
	ft_putendl_fd("exit", STDOUT_FILENO);
	exit(ft_atoi(find_val_in_dict(env, "?")));
}
