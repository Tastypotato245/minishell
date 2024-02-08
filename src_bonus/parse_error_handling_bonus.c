/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error_handling_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:09:30 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:09:46 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_bonus.h>
#include <tokenize_bonus.h>
#include <parse_bonus.h>

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
