/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_except.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:38:34 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/06 15:07:16 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_except.h"

void	exit_handler(int case_num, char *program_name, char *object)
{
	if (program_name != NULL)
	{
		ft_putstr_fd(program_name, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (object != NULL)
	{
		ft_putstr_fd(object, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (case_num == 0)
	{
		ft_putendl_fd("parse error", STDERR_FILENO);
		exit(1);
	}
	else if (case_num == 127)
		ft_putstr_fd("command not found", STDERR_FILENO);
	else
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(case_num);
}

int	func_guard(int result, char *program_name, char *object)
{
	if (result == -1)
		exit_handler(1, program_name, object);
	return (result);
}

void	*null_guard(void *pointer, char *program_name, char *object)
{
	if (pointer == NULL)
		exit_handler(1, program_name, object);
	return (pointer);
}
