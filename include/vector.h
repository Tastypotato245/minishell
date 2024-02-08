/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:15:36 by younghoc          #+#    #+#             */
/*   Updated: 2024/01/30 19:45:43 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

typedef struct s_vector
{
	char	*data;
	int		len;
	int		cap;
}	t_vector;

void		init_vector(t_vector *vector);
char		*push_back(t_vector *vector, char c);
char		*push_str(t_vector *vector, char *str);
void		destroy_vector(t_vector *vector);

#endif
