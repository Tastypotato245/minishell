/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_print_token_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:13:37 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:13:38 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <panic_bonus.h>
#include <tokenize_bonus.h>

void	print_token(void *token)
{
	if (((t_token *)token)->category == T_OR)
		printf("T_OR\n");
	else if (((t_token *)token)->category == T_AND)
		printf("T_AND\n");
	else if (((t_token *)token)->category == T_PIPE)
		printf("T_PIPE\n");
	else if (((t_token *)token)->category == T_L_PAREN)
		printf("T_L_PAREN\n");
	else if (((t_token *)token)->category == T_R_PAREN)
		printf("T_R_PAREN\n");
	else if (((t_token *)token)->category == T_IN_REDIRECT)
		printf("T_IN_REDIRECT\n");
	else if (((t_token *)token)->category == T_OUT_REDIRECT)
		printf("T_OUT_REDIRECT\n");
	else if (((t_token *)token)->category == T_APPEND_REDIRECT)
		printf("T_APPEND_REDIRECT\n");
	else if (((t_token *)token)->category == T_HERE_DOC)
		printf("T_HERE_DOC\n");
	else if (((t_token *)token)->category == T_WORD)
		printf("T_WORD(%s)\n", ((t_token *)token)->content);
	else if (((t_token *)token)->category == T_ERROR)
		printf("T_ERROR\n");
	else
		panic("uncatched token category");
}
