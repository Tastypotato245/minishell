/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_document_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:15:51 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/06 18:15:52 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <here_document.h>
#include <fcntl.h>

char	*random_path(void)
{
	int				urandom_fd;
	unsigned char	b;
	int				i;
	char			*random;

	random = null_guard(ft_calloc(70, sizeof(char)),
			PROGRAM_NAME, "random64().");
	ft_strlcpy(random, "/tmp/", 70);
	urandom_fd = func_guard(open("/dev/urandom", O_RDONLY),
			PROGRAM_NAME, "random64().");
	i = 0;
	while (i < 64)
	{
		func_guard(read(urandom_fd, &b, 1), PROGRAM_NAME, "random64().");
		random[i + 5] = "01234567890abcdef"[b % 16];
		i++;
	}
	close(urandom_fd);
	return (random);
}
