/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_libft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:03:08 by kyusulee          #+#    #+#             */
/*   Updated: 2023/10/27 19:46:27 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		++len;
	return (len);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	if (!s)
		return (-1);
	return (write(1, s, ft_strlen(s)));
}

int	ft_putposinbr(unsigned int un)
{
	char			str[10];
	int				len;

	len = 0;
	while (un != 0)
	{
		str[9 - len] = '0' + un % 10;
		un /= 10;
		++len;
	}
	return (write(1, &str[10 - len], len));
}

int	ft_puthex(unsigned long long val, int is_upper)
{
	char			*hex;
	char			str[16];
	int				len;

	if (val == 0)
		return (ft_putchar('0'));
	if (is_upper)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	len = 0;
	while (val)
	{
		str[15 - len] = hex[val % 16];
		val /= 16;
		++len;
	}
	return (write(1, &str[16 - len], len));
}
