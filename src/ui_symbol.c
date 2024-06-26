/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_symbol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:48:01 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/06 18:17:18 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ui.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <kyusulib.h>
#include <minishell.h>

void	print_symbol(void)
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
	if (DEBUG)
		printf(" *** DEBUG_MODE *** \t *** DEBUG_MODE *** \n");
}
