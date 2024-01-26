/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_writers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:32:32 by kyusulee          #+#    #+#             */
/*   Updated: 2023/11/12 13:00:46 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_writer_c(va_list arg)
{
	char	c;

	c = (char)va_arg(arg, int);
	return (ft_putchar(c));
}

int	ft_writer_s(va_list arg)
{
	char	*s;

	s = va_arg(arg, char *);
	if (!s)
		return (ft_putstr("(null)"));
	return (ft_putstr(s));
}

int	ft_writer_udi(va_list arg, int is_un)
{
	int	nbr;
	int	len;

	nbr = va_arg(arg, int);
	if (nbr == 0)
		return (ft_putchar('0'));
	if (!is_un && nbr < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		len = ft_putposinbr(-nbr);
		if (len == -1)
			return (-1);
		++len;
		return (len);
	}
	return (ft_putposinbr(nbr));
}

int	ft_writer_x(va_list arg, int is_upper)
{
	unsigned int	nbr;

	nbr = va_arg(arg, int);
	return (ft_puthex(nbr, is_upper));
}

int	ft_writer_p(va_list arg)
{
	void	*address;
	int		len;

	address = va_arg(arg, void *);
	if (ft_putstr("0x") == -1)
		return (-1);
	len = ft_puthex((unsigned long long)address, 0);
	if (len == -1)
		return (-1);
	len += 2;
	return (len);
}
