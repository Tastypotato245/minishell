/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:57:14 by kyusulee          #+#    #+#             */
/*   Updated: 2024/01/28 21:28:05 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../kyusulib/kyusulib.h"
# include <stdio.h>

typedef struct s_pipe
{
	t_list	*words;
	t_list	*rds;
}			t_pipe;

typedef enum e_rd_category
{
	IN_RD = 0,
	OUT_RD,
	APPEND_RD
}			t_rd_category;

typedef struct s_rd
{
	t_rd_category	category;
	char			*word;
}				t_rd;

#endif
