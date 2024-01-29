/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_ctl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:56:34 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/29 14:25:29 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_cmd_lst	*new_cmd_lst(void)
{
	t_cmd_lst	*lst;

	lst = nullguard(malloc(sizeof(new_cmd_lst)), PROGRAM, "in new_cmd_lst");
}

void	cmd_lst_new_node_back()
{


}
