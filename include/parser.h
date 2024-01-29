/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:39:28 by younghoc          #+#    #+#             */
/*   Updated: 2024/01/29 13:39:29 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <minishell.h>

typedef enum e_tree_category
{
	TR_LIST_AND,
	TR_LIST_OR,
	TR_LIST_END,
	TR_PIPE_CONTINUE,
	TR_PIPE_END,
	TR_SMPL_CMD,
	TR_SMPL_CMD_END,
	TR_WORD_CONTINUE,
	TR_REDIRECT_IN,
	TR_REDIRECT_OUT,
	TR_REDIRECT_APPEND,
	TR_REDIRECT_HERE_DOC,
}	t_tree_category;

typedef struct s_tree
{
	t_tree_category	category;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

t_tree	*parse(t_list *tokens);

#endif
