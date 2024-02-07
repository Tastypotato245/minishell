/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_document_unlink.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:56:35 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/07 15:56:38 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <here_document.h>

void	unlink_here_doc_temp_file(t_list **here_doc_list)
{
	t_list	*node;

	node = *here_doc_list;
	while (node)
	{
		func_guard(unlink(node->content),
			PROGRAM_NAME, "unlink_here_doc_temp_file().");
		node = node->next;
	}
	ft_lstclear(here_doc_list, free);
}
