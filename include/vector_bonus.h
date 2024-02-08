/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:21:58 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:22:05 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_BONUS_H
# define VECTOR_BONUS_H

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
