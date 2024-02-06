/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:50:26 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/05 21:59:44 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <dirent.h>

static void	set_pwd(char mod, t_pair *n_pwd, t_pair *o_pwd)
{
	char	*buf;

	if (mod == 'o')
	{
		if (n_pwd != NULL && o_pwd != NULL && n_pwd->val != NULL)
		{
			free(o_pwd->val);
			o_pwd->val = ft_strdup(n_pwd->val);
		}
	}
	else if (mod == 'n' && n_pwd != NULL)
	{
		buf = getcwd(NULL, 0);
		if (buf == NULL)
			print_error(BTIN_CD, NULL, \
					"error retrieving current directory: getcwd");
		else
		{
			free(n_pwd->val);
			n_pwd->val = buf;
		}
	}
}

static int	normal_cd(t_pair *n_pwd, t_pair *o_pwd, char *target_dir)
{
	set_pwd('o', n_pwd, o_pwd);
	if (chdir(target_dir) == -1)
		return (return_handler(1, BTIN_CD, target_dir, strerror(errno)));
	set_pwd('n', n_pwd, o_pwd);
	return (0);
}

static int	go_home(t_dict *env, t_pair *n_pwd, t_pair *o_pwd)
{
	char	*target_dir;

	target_dir = find_val_in_dict(env, "HOME");
	if (target_dir == NULL)
		return (return_handler(1, BTIN_CD, NULL, "HOME not set"));
	return (normal_cd(n_pwd, o_pwd, target_dir));
}

int	builtin_cd(t_dict *env, t_exe_lst *exes)
{
	t_exe_node	*exe;
	t_pair		*n_pwd;
	t_pair		*o_pwd;

	n_pwd = find_pair_in_dict(env, "PWD");
	o_pwd = find_pair_in_dict(env, "OLDPWD");
	if (exes->size == 1)
		return (go_home(env, n_pwd, o_pwd));
	exe = exes->head->next;
	return (normal_cd(n_pwd, o_pwd, ft_strdup(exe->word)));
}
