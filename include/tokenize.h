/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:57:58 by younghoc          #+#    #+#             */
/*   Updated: 2024/01/28 12:58:00 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

# include <minishell.h>

typedef enum e_token_category
{
	T_OR,
	T_AND,
	T_PIPE,
	T_L_PAREN,
	T_R_PAREN,
	T_IN_REDIRECT,
	T_OUT_REDIRECT,
	T_APPEND_REDIRECT,
	T_HERE_DOC,
	T_WORD,
	T_ERROR,
}	t_token_category;

typedef struct s_token
{
	t_token_category	category;
	char				*content;
}	t_token;

t_list	*tokenize(const char *line);

t_token	*categorize_token(const char *line, size_t *i);

t_token	*create_or_token(size_t *i);
t_token	*create_and_token(size_t *i);
t_token	*create_pipe_token();
t_token	*create_lparen_token(size_t *i);
t_token	*create_rparen_token(size_t *i);
t_token	*create_in_redirect_token(size_t *i);
t_token	*create_out_redirect_token(size_t *i);
t_token	*create_append_redirect_token(size_t *i);
t_token	*create_here_doc_token(size_t *i);
t_token	*create_word_token(const char *line, size_t *i);
t_token	*create_error_token();

#endif
