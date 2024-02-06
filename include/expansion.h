/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:37:22 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/06 13:15:22 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include <dict.h>
# include <list.h>

char		*parameter_expansion(const char *word, t_dict *env);
int			check_valid_dollar(const char *word);
t_exe_lst	*filename_expansion(char *word);
char		*quote_removal(char	*word);

// expansion_ctl1.c
void		exes_export_expansion(t_exe_lst *exes, t_dict *env);
void		cmds_expansion(t_cmd_lst *cmds, t_dict *env);

// expansion_ctl2.c
int			expand_is_ambiguous(t_rd_node *rd, t_dict *env);

#endif
