/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_symbol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:48:01 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/31 15:13:50 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ui.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <kyusulib.h>
#include <minishell.h>

void		print_symbol(void)
{
	int		fd;
	int		rt;
	char	*symbol;

	fd = open(SYMBOL_FILE, O_RDONLY);

	if (fd < 0)
	{
		printf("Hello FrankShell!!\n");
		return ;
	}
	symbol = null_guard(malloc(BUFFER_SIZE), PROGRAM_NAME, "print_symbol().");
	rt = read(fd, symbol, BUFFER_SIZE);
	func_guard(rt, PROGRAM_NAME, "print_symbol().");
	symbol[rt] = '\0';
	printf("%s", symbol);
	free(symbol);
	close(fd);
}
