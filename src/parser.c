/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:39:56 by younghoc          #+#    #+#             */
/*   Updated: 2024/01/29 13:40:03 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_tree	*parse_list(t_list *tokens)
{
}

t_tree	*parse_pipeline(t_list *tokens)
{
}

t_tree	*parse_simple_command(t_list *tokens)
{
}

t_tree	*parse_redirection(t_list *tokens)
{
}

t_tree	*parse(t_list *tokens)
{
	return (parse_list(tokens));
}
