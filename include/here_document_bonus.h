/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_document_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:20:01 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:22:57 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERE_DOCUMENT_BONUS_H
# define HERE_DOCUMENT_BONUS_H
# include <parse_bonus.h>
# include <dict_bonus.h>

int		here_doc_traverse(t_tree *tree, t_list **here_doc_list, \
		t_dict *env_dict);
void	unlink_here_doc_temp_file(t_list **here_doc_list);

char	*random_path(void);
int		is_contain_quote(char *limiter);

#endif
