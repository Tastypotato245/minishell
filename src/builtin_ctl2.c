/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_ctl2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:27:21 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/06 14:28:10 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <kyusulib.h>

void	print_error(char *cmd, char *obj, char *str)
{
	ft_putstr_fd(PROGRAM_NAME, STDERR_FILENO);
	if (cmd != NULL)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
	}
	if (obj != NULL)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd("`", STDERR_FILENO);
		ft_putstr_fd(obj, STDERR_FILENO);
		ft_putstr_fd("\'", STDERR_FILENO);
	}
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(str, STDERR_FILENO);
}

int	return_handler(int return_no, char *cmd, char *obj, char *str)
{
	print_error(cmd, obj, str);
	return (return_no);
}
