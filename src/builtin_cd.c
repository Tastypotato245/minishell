/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:50:26 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/05 13:02:07 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <dirent.h>

static void	update_pwd(t_pair *n_pwd, t_pair *o_pwd, char *new_pwd)
{
	char	*buf;

	if (o_pwd != NULL)
	{
		free(o_pwd->val);
		o_pwd->val = NULL;
		buf = getcwd(NULL, 0);
		if (buf == NULL)
			print_error(BTIN_CD, "error retrieving current directory: getcwd", \
					strerror(errno));
		o_pwd->val = buf;
	}
	if (n_pwd != NULL)
	{
		free(n_pwd->val);
		n_pwd->val = new_pwd;
	}
}

static int	go_home(t_dict *env, t_pair *n_pwd, t_pair *o_pwd)
{
	char	*target_dir;
	DIR		*dir;
	char	*buf;

	target_dir = ft_strdup(find_val_in_dict(env, "HOME"));
	if (target_dir == NULL)
		return (return_handler(1, BTIN_CD, NULL, "HOME not set"));
	dir = opendir(target_dir);
	if (dir == NULL)
		return (return_handler(1, BTIN_CD, target_dir, strerror(errno)));
	else
		closedir(dir);
	update_pwd(n_pwd, o_pwd, target_dir);
	if (chdir(target_dir) == -1)
		return (return_handler(1, BTIN_CD, target_dir, strerror(errno)));
	if (n_pwd != NULL)
	{
		free(n_pwd->val);
		buf = getcwd(NULL, 0);
		if (buf == NULL)
			print_error(BTIN_CD, "error retrieving current directory: getcwd", \
					strerror(errno));
		n_pwd->val = buf;
	}
	return (0);
}

static int	absolute_chdir(t_pair *n_pwd, t_pair *o_pwd, char *target_dir)
{
	DIR		*dir;
	char	*buf;

	dir = opendir(target_dir);
	if (dir == NULL)
		return (return_handler(1, BTIN_CD, target_dir, strerror(errno)));
	else
		closedir(dir);
	update_pwd(n_pwd, o_pwd, target_dir);
	if (chdir(target_dir) == -1)
		return (return_handler(1, BTIN_CD, target_dir, strerror(errno)));
	if (n_pwd != NULL)
	{
		free(n_pwd->val);
		buf = getcwd(NULL, 0);
		if (buf == NULL)
			print_error(BTIN_CD, "error retrieving current directory: getcwd", \
					strerror(errno));
		n_pwd->val = buf;
	}
	return (0);
}

static int	relative_chdir(t_exe_node *exe, t_pair *n_pwd, t_pair *o_pwd)
{
	char	*target_dir_part;
	char	*target_dir;
	char	*buf;

	buf = getcwd(NULL, 0);
	if (buf == NULL)
		print_error(BTIN_CD, "error retrieving current directory: getcwd", \
				strerror(errno));
	target_dir_part = ft_strjoin(buf, "/");
	target_dir = ft_strjoin(target_dir_part, exe->word);
	free(buf);
	free(target_dir_part);
	return (absolute_chdir(n_pwd, o_pwd, target_dir));
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
	if (exe->word[0] == '/')
		return (absolute_chdir(n_pwd, o_pwd, exe->word));
	return (relative_chdir(exe, n_pwd, o_pwd));
}
