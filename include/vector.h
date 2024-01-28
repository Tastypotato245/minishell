/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:15:36 by younghoc          #+#    #+#             */
/*   Updated: 2024/01/28 16:15:38 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

# include <stdlib.h>

typedef struct s_vector
{
	char	*data;
	int		len;
	int		cap;
}	t_vector;

void		init_vector(t_vector *vector);
char		*push_back(t_vector *vector, char c);
void		destroy_vector(t_vector *vector);

#endif
