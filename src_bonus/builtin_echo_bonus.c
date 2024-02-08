/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:15:27 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:15:28 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin_bonus.h>

static int	is_n(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i++] != 'n')
			return (0);
	}
	return (1);
}

static int	is_option_n(t_exe_node **exe)
{
	int	option_n;

	option_n = 0;
	while ((*exe))
	{
		if (ft_strncmp((*exe)->word, "-", 1) == 0 && is_n(&((*exe)->word[1])))
			option_n = 1;
		else
			return (option_n);
		(*exe) = (*exe)->next;
	}
	return (option_n);
}

int	builtin_echo(t_exe_lst *exes)
{
	t_exe_node	*exe;
	int			option_n;

	exe = exes->head->next;
	option_n = is_option_n(&exe);
	while (exe)
	{
		if (exe->next == NULL)
			ft_putstr_fd(exe->word, STDOUT_FILENO);
		else
		{
			ft_putstr_fd(exe->word, STDOUT_FILENO);
			ft_putstr_fd(" ", STDOUT_FILENO);
		}
		exe = exe->next;
	}
	if (option_n == 0)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}
