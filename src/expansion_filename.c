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

//static int	is_matched(char *word, char *name)
//{
//}

t_exe_lst	*filename_expansion(char *word)
{
	const size_t	wordlen = ft_strlen(word);
	t_exe_lst	*exes;

	(void)word;
	exes = new_exe_lst();
    DIR *dir = null_guard(opendir("."), PROGRAM_NAME, "filename_expansion().");
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
		if (word[0] != '.' && entry->d_name[0] == '.')
			continue ;
		if (word[wordlen - 1] == '/' && entry->d_type != DT_DIR)
			continue ;
		// if (is_matched(word, entry->d_name))
			exe_lst_new_back(exes, ft_strdup(entry->d_name));
    }
    closedir(dir);
	return (exes);
}
