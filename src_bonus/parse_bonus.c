/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:09:14 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:09:20 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse_bonus.h>
#include <tokenize_bonus.h>
#include <panic_bonus.h>

t_tree	*parse(t_list *tokens)
{
	t_tree	*tree;

	if (tokens == NULL)
		return (NULL);
	tree = parse_list(&tokens);
	if (tokens != NULL)
		return (print_parse_error(tokens, tree));
	return (tree);
}
