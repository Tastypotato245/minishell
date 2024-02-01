/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_document.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:38:56 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/01 16:38:57 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERE_DOCUMENT_H
# define HERE_DOCUMENT_H

# include <parse.h>

void	here_doc_traverse(t_tree *tree, t_list **here_doc_list);

#endif // !HERE_DOCUMENT_H
