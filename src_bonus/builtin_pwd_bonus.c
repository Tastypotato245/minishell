/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:15:52 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:15:53 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin_bonus.h>

int	builtin_pwd(void)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	if (buf == NULL)
		return (return_handler(1, BTIN_PWD, NULL, strerror(errno)));
	printf("%s\n", buf);
	free(buf);
	return (0);
}
