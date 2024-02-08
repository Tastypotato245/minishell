/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:20:57 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:22:39 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_BONUS_H
# define PARSE_BONUS_H

# include <list_bonus.h>

typedef enum e_tree_category
{
	TR_LIST_AND,
	TR_LIST_OR,
	TR_LIST_END,
	TR_PIPE_CONTINUE,
	TR_PIPE_END,
	TR_SMPL_CMD_CONTINUE,
	TR_SMPL_CMD_END,
	TR_WORD,
	TR_REDIRECT_IN,
	TR_REDIRECT_OUT,
	TR_REDIRECT_APPEND,
	TR_REDIRECT_HERE_DOC,
}	t_tree_category;

typedef struct s_tree
{
	t_tree_category	category;
	void			*left;
	void			*right;
}	t_tree;

t_tree	*parse(t_list *tokens);
t_tree	*parse_list(t_list **tokens);
t_tree	*parse_pipeline(t_list **tokens);
t_tree	*parse_simple_command(t_list **tokens);
t_tree	*parse_redirection(t_list **tokens);
t_tree	*parse_word(t_list **tokens);

void	print_tree(t_tree *tree, int step);
t_tree	*destroy_tree(t_tree *tree);

t_tree	*print_parse_error(t_list *tokens, t_tree *tree);

#endif
