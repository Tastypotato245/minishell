/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:50:12 by kyusulee          #+#    #+#             */
/*   Updated: 2023/10/19 14:43:09 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_requlen(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	size_t	sublen;

	i = 0;
	slen = ft_strlen(s);
	sublen = 0;
	if (slen <= start)
		return (0);
	while (s[start] && i < len)
	{
		++start;
		++i;
		++sublen;
	}
	return (sublen);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	sublen;

	if (!s)
		return (NULL);
	sublen = ft_requlen(s, start, len);
	sub = (char *)malloc(sizeof(*s) * (sublen + 1));
	if (!sub)
		return (NULL);
	if (sublen == 0)
		sub[0] = '\0';
	else
		ft_strlcpy(sub, &s[start], sublen + 1);
	return (sub);
}
