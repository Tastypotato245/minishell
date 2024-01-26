/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:06:40 by kyusulee          #+#    #+#             */
/*   Updated: 2023/10/19 14:35:26 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putposinbr_fd(unsigned int n, int fd)
{
	char	str[21];
	int		i;

	str[20] = '\0';
	i = 19;
	while (n != 0)
	{
		str[i--] = '0' + n % 10;
		n /= 10;
	}
	++i;
	write(fd, &str[i], 20 - i);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putposinbr_fd(-n, fd);
	}
	else
		ft_putposinbr_fd(n, fd);
}
