/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:10:34 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/09 11:20:05 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_switcher(va_list arg, char c)
{
	if (c == 'c')
		return (ft_writer_c(arg));
	else if (c == 's')
		return (ft_writer_s(arg));
	else if (c == 'p')
		return (ft_writer_p(arg));
	else if (c == 'd' || c == 'i')
		return (ft_writer_udi(arg, 0));
	else if (c == 'u')
		return (ft_writer_udi(arg, 1));
	else if (c == 'x')
		return (ft_writer_x(arg, 0));
	else if (c == 'X')
		return (ft_writer_x(arg, 1));
	else if (c == '%')
		return (write(1, "%", 1));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		checker;
	int		i;
	va_list	arg;

	i = 0;
	len = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] != '%')
			checker = write(1, &format[i], 1);
		else
			checker = ft_switcher(arg, format[++i]);
		if (checker == -1)
			return (-1);
		len += checker;
		++i;
	}
	va_end(arg);
	return (len);
}
