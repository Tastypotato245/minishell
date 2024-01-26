/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:50:35 by kyusulee          #+#    #+#             */
/*   Updated: 2023/10/19 14:42:17 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	begin;
	size_t	end;

	if (!s1)
		return (NULL);
	begin = 0;
	end = ft_strlen(s1);
	while (begin < end && ft_strchr(set, s1[begin]) != NULL)
		++begin;
	while (end > begin && ft_strchr(set, s1[end - 1]) != NULL)
		--end;
	str = (char *)malloc(sizeof(*s1) * (end - begin + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (begin + i < end)
	{
		str[i] = s1[begin + i];
		++i;
	}
	str[i] = '\0';
	return (str);
}
