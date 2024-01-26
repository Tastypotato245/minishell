/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:34:02 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/15 17:34:03 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_lstset_end(t_lst *lst)
{
	while (lst->end < lst->len - 1)
	{
		if (lst->str[lst->end] == '\n')
			return (0);
		++(lst->end);
	}
	return (-1);
}

char	*make_str_from_lst(t_lst **lst, t_lst *now)
{
	char	*str;
	size_t	i;
	size_t	len;

	if (now->end == now->len)
		return (ft_lstdel_one(lst, now->fd));
	len = now->end - now->bgn + 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (ft_lstdel_one(lst, now->fd));
	i = 0;
	while (i < len)
	{
		str[i] = now->str[now->bgn + i];
		++i;
	}
	str[len] = '\0';
	now->end = now->end + 1;
	now->bgn = now->end;
	ft_lstset_end(now);
	return (str);
}

char	*read_str_from_fd(t_lst **lst, t_lst *now)
{
	ssize_t	rt_val;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (ft_lstdel_one(lst, now->fd));
	while (1)
	{
		rt_val = read(now->fd, buf, BUFFER_SIZE);
		if (rt_val == 0 || rt_val == -1)
			break ;
		if (ft_lstappend_str(now, buf, rt_val) != 0)
			break ;
		if (now->str[now->end] == '\n')
			break ;
	}
	free(buf);
	if (rt_val == -1 || now->str == NULL)
		return (ft_lstdel_one(lst, now->fd));
	return (make_str_from_lst(lst, now));
}

char	*get_next_line(int fd)
{
	static t_lst	*lst;
	t_lst			*now;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (lst == NULL)
	{
		if (ft_lstnewadd_front(&lst, fd) != 0)
			return (NULL);
		now = lst;
	}
	else
	{
		now = ft_lstfind_lst(lst, fd);
		if (now == NULL)
		{
			if (ft_lstnewadd_front(&lst, fd) != 0)
				return (NULL);
			now = lst;
		}
	}
	return (read_str_from_fd(&lst, now));
}
