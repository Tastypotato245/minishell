/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:36:10 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/29 18:05:00 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	execute_test(void)
{
	t_exe_lst	*exes;
	t_rd_lst	*rds;
	t_cmd_lst	*cmds;

	exes = new_exe_lst();
	rds = new_rd_lst();
	cmds = new_cmd_lst();
	exe_lst_new_back(exes, "echo");
	exe_lst_new_back(exes, "-n");
	exe_lst_new_back(exes, "hello");
	rd_lst_new_back(rds, 1, "outfile");
	cmd_lst_new_back(cmds, exes, rds);
	print_cmd_lst(cmds);
}
