/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_ctl2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:10:26 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/06 13:15:24 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expansion.h>
#include <stdlib.h>

int	expand_is_ambiguous(t_rd_node *rd, t_dict *env)
{
	t_exe_lst	*exes;
	char		*buf;

	buf = parameter_expansion(rd->file, env);
	exes = filename_expansion(buf);
	free(buf);
	if (exes->size > 1)
		return (1);
	free(rd->file);
	rd->file = quote_removal(exes->head->word);
	return (0);
}
