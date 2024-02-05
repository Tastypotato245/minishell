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

#include <expansion.h>

t_exe_lst	*filename_expansion(char *word)
{
	t_exe_lst	*exes;

	(void)word;
	exes = new_exe_lst();
	exe_lst_new_back(exes, ft_strdup("hello"));
	exe_lst_new_back(exes, ft_strdup("word"));
	return (exes);
}
