/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:50:48 by kyusulee          #+#    #+#             */
/*   Updated: 2023/10/19 14:35:44 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_c_strdup(const char c, const char *s1)
{
	char	*str;
	size_t	i;
	size_t	len;

	if (!s1)
		return (NULL);
	len = 0;
	while (s1[len] && s1[len] != c)
		++len;
	str = (char *)malloc(sizeof(*s1) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != c)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static size_t	ft_get_arrlen(const char *s, const char c)
{
	size_t	arrlen;
	size_t	i;
	int		can_cnt_word;

	can_cnt_word = 1;
	arrlen = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			can_cnt_word = 1;
		else if (can_cnt_word == 1)
		{
			can_cnt_word = 0;
			arrlen++;
		}
		i++;
	}
	return (arrlen);
}

static char	*ft_free_alloc_arr(char **results)
{
	size_t	i;

	if (!results)
		return (NULL);
	i = 0;
	while (results[i])
		free(results[i++]);
	free(results);
	return (NULL);
}

static char	**ft_alloc_word(const char *s, const char c, char **results)
{
	size_t		i;
	size_t		j;
	int			can_cnt_word;

	can_cnt_word = 1;
	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			can_cnt_word = 1;
		else if (can_cnt_word == 1)
		{
			can_cnt_word = 0;
			results[j] = ft_c_strdup(c, &s[i]);
			if (!(results[j++]))
			{
				ft_free_alloc_arr(results);
				return (NULL);
			}
		}
		++i;
	}
	results[j] = 0;
	return (results);
}

char	**ft_split(char const *s, char c)
{
	char	**results;
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = ft_get_arrlen(s, c);
	results = malloc(sizeof(char *) * (len + 1));
	if (!results)
		return (NULL);
	results[len] = NULL;
	results = ft_alloc_word(s, c, results);
	if (!results)
		return (NULL);
	return (results);
}
