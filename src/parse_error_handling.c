/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error_handling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:52:26 by younghoc          #+#    #+#             */
/*   Updated: 2024/01/31 16:52:27 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <tokenize.h>
#include <parse.h>

t_tree	*print_parse_error(t_list *tokens, t_tree *tree)
{
	t_token	*token;

	if (tree == NULL)
		return (NULL);
	ft_putstr_fd(PROGRAM_NAME, STDERR_FILENO);
	ft_putstr_fd(": syntax error near unexpected token `", STDERR_FILENO);
	token = get_first_token(tokens);
	print_error_token(token);
	ft_putstr_fd("'\n", STDERR_FILENO);
	destroy_tree(tree);
	return (NULL);
}
