/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:19:50 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:23:04 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_BONUS_H
# define EXPANSION_BONUS_H

# include <dict_bonus.h>
# include <list_bonus.h>

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
