/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_check_validity_of_tokens.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:22:43 by younghoc          #+#    #+#             */
/*   Updated: 2024/01/31 15:22:45 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenize.h>
#include <minishell.h>

static int	is_error_token(t_token *token)
{
	if (token->category == T_ERROR)
		return (1);
	return (0);
}

static void	print_syntax_error(t_list *tokens)
{
	(void)tokens;
	ft_putstr_fd(PROGRAM_NAME, STDERR_FILENO);
	ft_putstr_fd(": syntax error near unexpected token `asd'", STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

int	is_valid_tokens(t_list *tokens)
{
	while (tokens)
	{
		if (is_error_token(tokens->content))
		{
			print_syntax_error(tokens);
			return (-1);
		}
		tokens = tokens->next;
	}
	return (0);
}
