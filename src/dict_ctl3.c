#include <dict.h>

static void	dict_add_pair_in_sort(t_dict *dict, t_pair *new)
{
	t_pair	*pre;
	int		new_key_len;

	new_key_len = ft_strlen(new->key);
	if (ft_strncmp(new->key, dict->head->key, new_key_len + 1) <= 0)
	{
		new->next = dict->head;
		dict->head = new;
		dict->size += 1;
		return ;
	}
	pre = dict->head;
	while (pre->next)
	{
		if (ft_strncmp(new->key, pre->next->key, new_key_len + 1) <= 0)
			break ;
		pre = pre->next;
	}
	new->next = pre->next;
	if (pre->next == NULL)
		dict->tail = new;
	pre->next = new;
	dict->size += 1;
}

static void	dict_new_in_sort(t_dict *dict, char *key, char *val)
{
	t_pair	*new;

	new = null_guard(malloc(sizeof(*new)), PROGRAM_NAME, "dict_new_in_sort().");
	new->key = key;
	new->val = val;
	new->next = NULL;
	if (!dict->head)
	{
		dict->head = new;
		dict->tail = new;
		dict->size = 1;
		return ;
	}
	dict_add_pair_in_sort(dict, new);
	return ;
}

void	dict_modi_val_or_new_in_sort(t_dict *dict, char *key, char *val)
{
	t_pair	*tmp;

	if (!dict)
		exit_handler(1, PROGRAM_NAME, "dict is NULL: dict_mv_nis().");
	if (!key || key[0] == '\0')
		exit_handler(1, PROGRAM_NAME, "key is NULL or empty: dict_mv_nis().");
	tmp = find_pair_in_dict(dict, key);
	if (tmp == NULL)
		dict_new_in_sort(dict, key, val);
	else if (val == NULL)
		return ;
	else
		tmp->val = val;
}
