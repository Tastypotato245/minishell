/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:37:22 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/04 16:37:28 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

#include <dict.h>
#include <list.h>

char		*parameter_expansion(const char *word, t_dict *env);
t_exe_lst	*filename_expansion(char *word);
char		*quote_removal(char	*word);

#endif
