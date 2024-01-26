/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:50:22 by kyusulee          #+#    #+#             */
/*   Updated: 2023/10/15 15:36:41 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1len;
	size_t	s2len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = (char *)malloc(sizeof(*s1) * (s1len + s2len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1len + 1);
	ft_strlcpy(&str[s1len], s2, s2len + 1);
	return (str);
}
