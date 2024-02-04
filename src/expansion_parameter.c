/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_parameter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:39:17 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/04 16:39:19 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dict.h>
#include <expansion.h>
#include <list.h>
#include <vector.h>

void	handle_dollar(const char *word, size_t *i,
		t_vector *vector, t_dict *env)
{
	t_vector	key;
	char		*value;

	(void)key;
	(*i)++;
	if (word[*i] == '\0'
		|| (ft_strchr("\'\"_", word[*i]) == NULL && !ft_isalpha(word[*i])))
	{
		push_back(vector, '$');
		return ;
	}
	init_vector(&key);
	while (ft_isalpha(word[*i]) || ft_isdigit(word[*i]) || word[*i] == '_')
	{
		push_back(&key, word[*i]);
		(*i)++;
	}
	push_back(&key, '\0');
	value = find_val_in_dict(env, key.data);
	destroy_vector(&key);
	if (value != NULL)
		push_str(vector, value);
}

void	handle_single_quote(const char *word, size_t *i, t_vector *vector)
{
	push_back(vector, word[*i]);
	(*i)++;
	while (word[*i] != '\'')
	{
		push_back(vector, word[*i]);
		(*i)++;
	}
	push_back(vector, word[*i]);
	(*i)++;
}

void	handle_double_quote(const char *word, size_t *i,
		t_vector *vector, t_dict *env)
{
	push_back(vector, word[*i]);
	(*i)++;
	while (word[*i] != '\"')
	{
		if (word[*i] == '$')
		{
			handle_dollar(word, i, vector, env);
			continue ;
		}
		push_back(vector, word[*i]);
		(*i)++;
	}
	push_back(vector, word[*i]);
	(*i)++;
}

char	*parameter_expansion(const char *word, t_dict *env)
{
	t_vector	vector;
	size_t		i;

	init_vector(&vector);
	i = 0;
	while (word[i] != '\0')
	{
		if (word[i] == '\'')
			handle_single_quote(word, &i, &vector);
		else if (word[i] == '\"')
			handle_double_quote(word, &i, &vector, env);
		else if (word[i] == '$')
			handle_dollar(word, &i, &vector, env);
		else
		{
			push_back(&vector, word[i]);
			i++;
		}
	}
	push_back(&vector, '\0');
	return (vector.data);
}
