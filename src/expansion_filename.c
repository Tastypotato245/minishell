/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_filename.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:46:23 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/06 15:08:36 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>
#include <minishell.h>
#include <expansion.h>
#include <dirent.h>
#include <kyusulib.h>

static int	is_matched(const char *pattern, const char *string,
		int in_single_quotes, int in_double_quotes)
{
	while (*pattern && *string)
	{
		if (*pattern == '\'' && !in_double_quotes)
			in_single_quotes = !in_single_quotes;
		else if (*pattern == '\"' && !in_single_quotes)
			in_double_quotes = !in_double_quotes;
		if (*pattern == '*' && !in_single_quotes && !in_double_quotes)
		{
			if (is_matched(pattern + 1, string,
					in_single_quotes, in_double_quotes))
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
	if (*pattern == '*' && *(pattern + 1) == '\0'
		&& !in_single_quotes && !in_double_quotes)
		return (1);
	return (*pattern == *string);
}

static void	inner_while(char *word, int only_dir,
		t_exe_lst *exes, struct dirent *entry)
{
	if (!((word[0] != '.' && entry->d_name[0] == '.')
			|| (only_dir && entry->d_type != DT_DIR))
		&& is_matched(word, entry->d_name, 0, 0))
	{
		if (only_dir)
			exe_lst_new_back(exes, ft_strjoin(entry->d_name, "/"));
		else
			exe_lst_new_back(exes, ft_strdup(entry->d_name));
	}
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
		inner_while(word, only_dir, exes, entry);
		entry = readdir(dir);
	}
	closedir(dir);
	if (exes->size == 0)
	{
		if (only_dir)
			exe_lst_new_back(exes, ft_strjoin(word, "/"));
		else
			exe_lst_new_back(exes, ft_strdup(word));
	}
	return (exes);
}
