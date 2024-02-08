/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_document_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:08:06 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:08:17 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <here_document_bonus.h>
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

int	is_contain_quote(char *limiter)
{
	const size_t	limiter_len = ft_strlen(limiter);
	size_t			i;

	i = 0;
	while (i < limiter_len)
	{
		if (ft_strchr("\"\'", limiter[i]))
			return (1);
		i++;
	}
	return (0);
}
