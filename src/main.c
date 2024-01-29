/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:57:47 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/28 21:55:38 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(void)
{
	char	*line;

	print_frankshell_image();
	while (1)
	{
		line = readline("🍔 $ ");
		free(line);
	}
	return (0);
}
