/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:50:26 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/04 18:44:01 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <direct.h>


static int	relative_chdir()
{

}

int	builtin_cd(t_dict *env, t_exe_lst *exes)
{
	char		*target_dir;
	t_exe_node	*exe;
	t_pair		*pwd_pair;

	pwd_pair = find_pair_in_dict(env, "");
	if (exes->size == 1)
	{
		target_dir = find_val_in_dict(env, "HOME");
		if (target_dir == NULL)
			return (return_handler(1, BTIN_CD, NULL, "HOME not set"));
		if (chdir(target_dir) == -1)
			return (return_handler(1, BTIN_CD, target_dir, strerror(errno)));
		getcwd();
		return (0);
	}
	exe = exes->head->next;
	if (exe->word[0] == '/')
	{
		target_dir = exe->word;
		if (chdir(target_dir) == -1)
			return (return_handler(1, BTIN_CD, target_dir, strerror(errno)));
		return (0);
	}
	target_dir = ;
	if (chdir(target_dir) == -1)
		return (return_handler(1, BTIN_CD, target_dir, strerror(errno)));
	return (0);
}
