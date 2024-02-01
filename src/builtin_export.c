/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:09:39 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/01 18:38:43 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <stdio.h>

static int	print_declare(t_dict *env)
{
	t_pair	*tmp;	

	if (!env)
		exit_handler(1, PROGRAM_NAME, "dict is NULL: print_declare().");
	tmp = env->head;
	while (tmp)
	{
		if (tmp->val == NULL)
			printf("declare -x %s\n", tmp->key);
		else
			printf("declare -x %s=\"%s\"\n", tmp->key, tmp->val);
		tmp = tmp->next;
	}
	return (0);
}

static int	builtin_no_key(t_exe_node **tmp, int *no_key)
{
	(*no_key) = 1;
	print_error(BTIN_EXPORT, (*tmp)->word, "not a valid identifier");
	(*tmp) = (*tmp)->next;
	return (1);
}

static int	builtin_no_val(t_dict *env, t_exe_node **tmp, size_t i)
{
	char	*key;
	char	*val;

	key = ft_substr((*tmp)->word, 0, i);
	val = NULL;
	dict_modi_val_or_new_in_sort(env, key, val);
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
	dict_modi_val_or_new_in_sort(env, key, val);
	(*tmp) = (*tmp)->next;
}

int	builtin_export(t_dict *env, t_exe_lst *exes)
{
	t_exe_node	*tmp;
	size_t		i;
	int			no_key;

	if (exes->size == 1)
		return (print_declare(env));
	no_key = 0;
	tmp = exes->head->next;
	while (tmp)
	{
		i = 0;
		while (tmp->word[i] && tmp->word[i] != '=')
			i++;
		if (i == 0 && builtin_no_key(&tmp, &no_key))
			continue ;
		else if (i == ft_strlen(tmp->word) && builtin_no_val(env, &tmp, i))
			continue ;
		else
			builtin_export_normal(env, &tmp, &i);
	}
	return (no_key);
}
