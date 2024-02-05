/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_filename.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:46:23 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/05 13:46:24 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <expansion.h>
#include <dirent.h>
#include <kyusulib.h>

static int	is_matched(const char *pattern, const char *string)
{
	while (*pattern && *string)
	{
		if (*pattern == '*')
		{
			if (is_matched(pattern + 1, string))
				return (1);
			++string;
		}
		else
		{
			if (*pattern != *string)
				return (0);
			++pattern;
			++string;
		}
	}
	if (*pattern == '*' && *(pattern + 1) == '\0')
		return (1);
	return (*pattern == *string);
}

t_exe_lst	*filename_expansion(char *word)
{
	const size_t	wordlen = ft_strlen(word);
	const int		only_dir = word[wordlen - 1] == '/';
	t_exe_lst		*exes;
	DIR				*dir;
	struct dirent	*entry;

	if (only_dir)
		word[wordlen - 1] = '\0';
	exes = new_exe_lst();
	dir = null_guard(opendir("."), PROGRAM_NAME, "filename_expansion().");
	entry = readdir(dir);
	while (entry != NULL)
	{
		if ((word[0] != '.' && entry->d_name[0] == '.')
			|| (only_dir && entry->d_type != DT_DIR))
		{
			entry = readdir(dir);
			continue ;
		}
		if (is_matched(word, entry->d_name))
		{
			if (only_dir)
				exe_lst_new_back(exes, ft_strjoin(entry->d_name, "/"));
			else
				exe_lst_new_back(exes, ft_strdup(entry->d_name));
		}
		entry = readdir(dir);
	}
	closedir(dir);
	if (exes->size == 0)
		exe_lst_new_back(exes, ft_strdup(word));
	return (exes);
}
