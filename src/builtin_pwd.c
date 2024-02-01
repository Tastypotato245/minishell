/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:50:42 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/01 20:26:21 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>

int	builtin_pwd(void)
{
	char	*buf;

	buf = null_guard(getcwd(NULL, 0), PROGRAM_NAME, "builtin_pwd().");
	printf("%s\n", buf);
	free(buf);
	return (0);
}
