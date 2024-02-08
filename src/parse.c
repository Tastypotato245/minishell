/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:39:56 by younghoc          #+#    #+#             */
/*   Updated: 2024/01/30 19:54:25 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <tokenize.h>
#include <panic.h>

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
