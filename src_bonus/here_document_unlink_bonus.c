/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_document_unlink_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:08:00 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:08:02 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <here_document_bonus.h>

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
