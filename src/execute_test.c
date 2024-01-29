/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:36:10 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/29 18:16:24 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// normal exes and rds
void	make_cmd_test_0(t_cmd_lst *cmds)
{
	t_exe_lst	*exes;
	t_rd_lst	*rds;

	exes = new_exe_lst();
	rds = new_rd_lst();
	exe_lst_new_back(exes, "echo");
	exe_lst_new_back(exes, "-n");
	exe_lst_new_back(exes, "hello");
	rd_lst_new_back(rds, 1, "outfile");
	rd_lst_new_back(rds, 2, "outfile2");
	cmd_lst_new_back(cmds, exes, rds);
}

// multiple empty string in exes
void	make_cmd_test_1(t_cmd_lst *cmds)
{
	t_exe_lst	*exes;
	t_rd_lst	*rds;

	exes = new_exe_lst();
	rds = new_rd_lst();
	exe_lst_new_back(exes, "cat");
	exe_lst_new_back(exes, "-e");
	exe_lst_new_back(exes, "");
	exe_lst_new_back(exes, "");
	exe_lst_new_back(exes, "");
	rd_lst_new_back(rds, 0, "infile");
	rd_lst_new_back(rds, 2, "outfile");
	cmd_lst_new_back(cmds, exes, rds);
}

// one exes and empty string rd file
void	make_cmd_test_2(t_cmd_lst *cmds)
{
	t_exe_lst	*exes;
	t_rd_lst	*rds;

	exes = new_exe_lst();
	rds = new_rd_lst();
	exe_lst_new_back(exes, "touch");
	rd_lst_new_back(rds, 2, "");
	cmd_lst_new_back(cmds, exes, rds);
}

// empty exes and rds
void	make_cmd_test_3(t_cmd_lst *cmds)
{
	t_exe_lst	*exes;
	t_rd_lst	*rds;

	exes = new_exe_lst();
	rds = new_rd_lst();
	cmd_lst_new_back(cmds, exes, rds);
}

void	execute_test(void)
{
	t_cmd_lst	*cmds;

	cmds = new_cmd_lst();
	make_cmd_test_0(cmds);
	make_cmd_test_1(cmds);
	make_cmd_test_2(cmds);
	make_cmd_test_3(cmds);
	print_cmd_lst(cmds);
}
