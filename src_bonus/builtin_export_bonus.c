/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:15:43 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:15:48 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin_bonus.h>
#include <stdio.h>
#include <expansion_bonus.h>

static int	print_declare(t_dict *env)
{
	t_pair	*tmp;	

	if (!env)
		exit_handler(1, PROGRAM_NAME, "dict is NULL: print_declare().");
	tmp = env->head;
	while (tmp)
	{
		if (ft_strncmp(tmp->key, "?", 2) == 0)
		{
			tmp = tmp->next;
			continue ;
		}
		else if (tmp->val == NULL)
			printf("declare -x %s\n", tmp->key);
		else
			printf("declare -x %s=\"%s\"\n", tmp->key, tmp->val);
		tmp = tmp->next;
	}
	return (0);
}

static int	env_key_check(t_exe_node **tmp, char *word, int *rt)
{
	int	i;
	int	len;

	len = ft_strlen(word);
	if (!(ft_isalpha(word[0]) || word[0] == '_'))
	{
		(*tmp) = (*tmp)->next;
		(*rt) = 1;
		return (return_handler(0, BTIN_EXPORT, word, "not a valid identifier"));
	}
	i = 1;
	while (i < len && word[i] != '=')
	{
		if (!(ft_isalpha(word[i]) || ft_isdigit(word[i]) || word[i] == '_'))
		{
			(*tmp) = (*tmp)->next;
			(*rt) = 1;
			return (return_handler(0, BTIN_EXPORT, word, \
						"not a valid identifier"));
		}
		++i;
	}
	return (1);
}

static int	builtin_no_val(t_dict *env, t_exe_node **tmp, size_t i)
{
	char	*key;
	char	*val;

	key = ft_substr((*tmp)->word, 0, i);
	val = NULL;
	if (dict_modi_val_or_new(env, key, val))
		free(key);
	(*tmp) = (*tmp)->next;
	return (1);
}

static void	builtin_export_normal(t_dict *env, t_exe_node **tmp, size_t *i)
{
	char		*key;
	char		*val;

	key = ft_substr((*tmp)->word, 0, *i);
	++(*i);
	val = ft_substr((*tmp)->word, *i, ft_strlen((*tmp)->word) - *i);
	if (dict_modi_val_or_new(env, key, val))
		free(key);
	(*tmp) = (*tmp)->next;
}

int	builtin_export(t_dict *env, t_exe_lst *exes)
{
	t_exe_node	*tmp;
	size_t		i;
	int			rt;

	exes_export_expansion(exes, env);
	if (exes->size == 1)
		return (print_declare(env));
	rt = 0;
	tmp = exes->head->next;
	while (tmp)
	{
		i = 0;
		while (tmp->word[i] && tmp->word[i] != '=')
			i++;
		if (!env_key_check(&tmp, tmp->word, &rt))
			continue ;
		else if (i == ft_strlen(tmp->word) && builtin_no_val(env, &tmp, i))
			continue ;
		builtin_export_normal(env, &tmp, &i);
	}
	return (rt);
}
