/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_push_str_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:14:52 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:14:55 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector_bonus.h>
#include <kyusulib_bonus.h>

char	*push_str(t_vector *vector, char *str)
{
	const size_t	strlen = ft_strlen(str);
	size_t			i;

	i = 0;
	while (i < strlen)
	{
		push_back(vector, str[i]);
		i++;
	}
	return (vector->data);
}
