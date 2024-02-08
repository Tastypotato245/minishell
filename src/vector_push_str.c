/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_push_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:22:24 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/05 22:00:25 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <kyusulib.h>

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
