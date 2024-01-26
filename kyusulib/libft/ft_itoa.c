/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:50:58 by kyusulee          #+#    #+#             */
/*   Updated: 2023/10/27 15:02:53 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_nonzero(char *s_temp, int n)
{
	int				i;
	unsigned int	un;

	if (n < 0)
		un = -n;
	else
		un = n;
	i = 19;
	while (un != 0)
	{
		s_temp[i--] = '0' + un % 10;
		un /= 10;
	}
	if (n < 0)
		s_temp[i--] = '-';
	++i;
	return (i);
}

char	*ft_itoa(int n)
{
	char	s_temp[21];
	char	*str;
	int		i;

	s_temp[20] = '\0';
	i = 19;
	if (n == 0)
		s_temp[i] = '0';
	else
		i = ft_itoa_nonzero(s_temp, n);
	str = ft_strdup(&s_temp[i]);
	if (!str)
		return (NULL);
	return (str);
}
