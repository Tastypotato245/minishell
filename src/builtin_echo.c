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

int	builtin_echo(t_exe_lst *exes)
{
	t_exe_node	*exe;
	int			option_n;

	exe = exes->head->next;
	option_n = 0;
	if (ft_strlen(exe->word) == 2 && ft_strncmp(exe->word, "-n", 2) == 0)
	{
		option_n = 1;
		exe = exe->next;
	}
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
