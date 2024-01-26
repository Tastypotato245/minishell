/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:01:43 by kyusulee          #+#    #+#             */
/*   Updated: 2023/10/17 12:57:49 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_map_init(t_list **lst, t_list **new, void **tmp, t_list **lst_t)
{
	*lst = NULL;
	*new = NULL;
	*tmp = NULL;
	*lst_t = NULL;
}

static t_list	*ft_lstclear_null(t_list **lst, void *con, void (*del)(void *))
{
	t_list	*tmp;

	if (con)
		(*del)(con);
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	return (NULL);
}

static void	ft_lstadd_back_last(t_list **last, t_list *new)
{
	if (!last)
		return ;
	if (*last)
		(*last)->next = new;
	*last = new;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*new;
	void	*tmpcon;
	t_list	*newlst_tail;

	if (!lst || !f || !del)
		return (NULL);
	ft_map_init(&newlst, &new, &tmpcon, &newlst_tail);
	while (lst)
	{
		tmpcon = (*f)(lst->content);
		if (!tmpcon)
			return (ft_lstclear_null(&newlst, tmpcon, del));
		new = ft_lstnew(tmpcon);
		if (!new)
			return (ft_lstclear_null(&newlst, tmpcon, del));
		if (!newlst)
			newlst = new;
		ft_lstadd_back_last(&newlst_tail, new);
		lst = lst->next;
	}
	return (newlst);
}
