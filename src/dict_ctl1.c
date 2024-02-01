/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_ctl1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:53:55 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/01 18:19:05 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dict.h>

static void	dictionary_size_check(t_dict *dict)
{
	t_pair	*tmp;
	int		cnt;

	if (!dict)
		exit_handler(1, PROGRAM_NAME, "lst is NULL: dict_size_check().");
	cnt = 0;
	tmp = dict->head;
	while (tmp)
	{
		++cnt;
		tmp = tmp->next;
	}
	if (cnt != dict->size)
		exit_handler(1, PROGRAM_NAME, "size error: dict_size_check().");
	return ;
}

t_dict	*new_dictionary(void)
{
	t_dict	*dict;

	dict = null_guard(malloc(sizeof(*dict)), PROGRAM_NAME, "new_dictionary().");
	dict->head = NULL;
	dict->tail = NULL;
	dict->size = 0;
	return (dict);
}

void	dict_new_back(t_dict *dict, char *key, char *val)
{
	t_pair	*new;

	if (!dict)
		exit_handler(1, PROGRAM_NAME, "dict is NULL: dict_new_back().");
	if (!key || key[0] == '\0')
		exit_handler(1, PROGRAM_NAME, "key is NULL or empty : dict_new_back().");
	new = null_guard(malloc(sizeof(*new)), PROGRAM_NAME, "dict_new_back().");
	new->key = key;
	new->val = val;
	new->next = NULL;
	if (!dict->head)
	{
		dict->head = new;
		dict->tail = new;
		dict->size = 1;
	}
	else
	{
		dict->tail->next = new;
		dict->tail = new;
		dict->size += 1;
	}
	return ;
}

void	free_dict(t_dict *dict)
{
	t_pair	*tmp;	

	if (!dict)
		exit_handler(1, PROGRAM_NAME, "dict is NULL: free_dict().");
	dictionary_size_check(dict);
	while (dict->head)
	{
		tmp = dict->head;
		dict->head = dict->head->next;
		free_pair(tmp);
		tmp = NULL;
	}
	free(dict);
	dict = NULL;
}

void	print_dict(t_dict *dict)
{
	t_pair	*tmp;	

	if (!dict)
		exit_handler(1, PROGRAM_NAME, "dict is NULL: print_dict().");
	tmp = dict->head;
	printf(" - dictionary: \n");
	printf("\tkey=val\n");
	printf("\t-------\n");
	while (tmp)
	{
		printf("\t%s=%s\n", tmp->key, tmp->val);
		tmp = tmp->next;
	}
	return ;
}
