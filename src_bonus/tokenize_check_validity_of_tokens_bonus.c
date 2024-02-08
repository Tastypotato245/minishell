/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_check_validity_of_tokens_bonus.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:12:59 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:12:59 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenize_bonus.h>
#include <minishell_bonus.h>
#include <panic_bonus.h>

static int	is_error_token(t_token *token)
{
	if (token->category == T_ERROR)
		return (1);
	return (0);
}

t_token	*get_first_token(t_list *tokens)
{
	t_token	*token;

	while (tokens)
	{
		token = tokens->content;
		if (!is_error_token(token))
			return (token);
		tokens = tokens->next;
	}
	return (NULL);
}

void	print_error_token(t_token *token)
{
	if (token == NULL)
		ft_putstr_fd("newline", STDERR_FILENO);
	else if (((t_token *)token)->category == T_OR)
		ft_putstr_fd("||", STDERR_FILENO);
	else if (((t_token *)token)->category == T_AND)
		ft_putstr_fd("&&", STDERR_FILENO);
	else if (((t_token *)token)->category == T_PIPE)
		ft_putstr_fd("|", STDERR_FILENO);
	else if (((t_token *)token)->category == T_L_PAREN)
		ft_putstr_fd("(", STDERR_FILENO);
	else if (((t_token *)token)->category == T_R_PAREN)
		ft_putstr_fd(")", STDERR_FILENO);
	else if (((t_token *)token)->category == T_IN_REDIRECT)
		ft_putstr_fd("<", STDERR_FILENO);
	else if (((t_token *)token)->category == T_OUT_REDIRECT)
		ft_putstr_fd(">", STDERR_FILENO);
	else if (((t_token *)token)->category == T_APPEND_REDIRECT)
		ft_putstr_fd(">>", STDERR_FILENO);
	else if (((t_token *)token)->category == T_HERE_DOC)
		ft_putstr_fd("<<", STDERR_FILENO);
	else if (((t_token *)token)->category == T_WORD)
		ft_putstr_fd(token->content, STDERR_FILENO);
	else
		ft_putstr_fd("newline", STDERR_FILENO);
}

static void	print_tokenize_error(t_list *tokens)
{
	t_token	*token;

	ft_putstr_fd(PROGRAM_NAME, STDERR_FILENO);
	ft_putstr_fd(": syntax error near unexpected token `", STDERR_FILENO);
	token = get_first_token(tokens);
	print_error_token(token);
	ft_putstr_fd("'\n", STDERR_FILENO);
}

int	is_valid_tokens(t_list *tokens)
{
	while (tokens)
	{
		if (is_error_token(tokens->content))
		{
			print_tokenize_error(tokens);
			return (-1);
		}
		tokens = tokens->next;
	}
	return (0);
}
