/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:50:56 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/01 20:05:21 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>

static int	is_n(char *str)
{
	int	i;

	i = 0;
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
			printf("%s", exe->word);
		else
			printf("%s ", exe->word);
		exe = exe->next;
	}
	if (option_n == 0)
		printf("\n");
	return (0);
}
