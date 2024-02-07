/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_document.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:38:56 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/07 16:11:26 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERE_DOCUMENT_H
# define HERE_DOCUMENT_H
# include <parse.h>
# include <dict.h>

int		here_doc_traverse(t_tree *tree, t_list **here_doc_list, \
		t_dict *env_dict);
void	unlink_here_doc_temp_file(t_list **here_doc_list);

#endif
