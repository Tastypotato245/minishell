/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:34:44 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/05 20:46:10 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <dict.h>
#include <stdio.h>
#include <readline/readline.h>

static void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	set_signal(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	cntl_d(t_dict *env)
{
	ft_putendl_fd("\033[A\033[1C exit", STDERR_FILENO);
	exit(ft_atoi(find_val_in_dict(env, "?")));
}
