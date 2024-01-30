/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:57:47 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/29 21:02:23 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int argc, char **argv, char **env)
{
	char	*line;

	if (argc != 1 || (argc == 2 && ft_strncmp(argv[1], "debug", 5) != 0))
		exit_handler(0, PROGRAM_NAME, "enter ./minishell");
	print_frankshell_image();
	while (1)
	{
		line = readline("🍔 $ ");
		if (ft_strncmp(line, "test", 4) == 0)
			execute_test(env);
		free(line);
	}
	return (0);
}
