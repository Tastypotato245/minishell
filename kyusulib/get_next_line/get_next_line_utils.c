/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:34:13 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/15 17:34:13 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_lstnewadd_front(t_lst **lst, int fd)
{
	t_lst	*new;

	if (!lst)
		return (-1);
	new = (t_lst *)malloc(sizeof(*new));
	if (!new)
		return (-2);
	new->fd = fd;
	new->str = NULL;
	new->bgn = 0;
	new->end = 0;
	new->len = 0;
	new->cap = 0;
	new->next = NULL;
	if (*lst)
		new->next = *lst;
	*lst = new;
	return (0);
}

t_lst	*ft_lstfind_lst(t_lst *lst, int fd)
{
	while (lst)
	{
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

int	ft_lstcap_change(t_lst *lst, size_t new_cap)
{
	size_t	i;
	char	*new_str;

	if (!lst)
		return (-1);
	new_str = (char *)malloc(sizeof(char) * new_cap);
	if (!new_str)
	{
		free(lst->str);
		lst->str = NULL;
		return (-2);
	}
	i = 0;
	while (i < lst->len)
	{
		new_str[i] = lst->str[i];
		++i;
	}
	if (lst->str != NULL)
		free(lst->str);
	lst->str = new_str;
	lst->cap = new_cap;
	return (0);
}

void	*ft_lstdel_one(t_lst **lst, int fd)
{
	t_lst	*tmp;
	t_lst	*pre;

	if ((*lst)->fd == fd)
	{
		tmp = (*lst)->next;
		free((*lst)->str);
		free(*lst);
		*lst = tmp;
	}
	else
	{
		pre = *lst;
		while (pre->next)
		{
			if (pre->next->fd == fd)
				break ;
			pre = pre->next;
		}
		tmp = pre->next;
		pre->next = tmp->next;
		free(tmp->str);
		free(tmp);
	}
	return (NULL);
}

int	ft_lstappend_str(t_lst *lst, char *buf, size_t len)
{
	size_t	i;
	int		rt;

	rt = -1;
	if ((size_t)(-1) - len < lst->len)
		return (rt);
	if (lst->len + len > lst->cap)
	{
		if (lst->len + len > lst->cap * 2)
			rt = ft_lstcap_change(lst, lst->len + len);
		else
			rt = ft_lstcap_change(lst, lst->cap * 2);
		if (rt != 0)
			return (rt);
	}
	i = 0;
	while (i < len)
	{
		lst->str[lst->len + i] = buf[i];
		++i;
	}
	lst->len = lst->len + len;
	ft_lstset_end(lst);
	return (0);
}
