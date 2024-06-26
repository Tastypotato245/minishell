/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_document_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:07:52 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 14:24:36 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <panic_bonus.h>
#include <minishell_bonus.h>
#include <here_document_bonus.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <unistd.h>
#include <signal_handler_bonus.h>
#include <expansion_bonus.h>

static void	inner_while(int heredoc_fd, char **line,
		t_dict *env_dict, int do_expansion)
{
	char	*tmp;

	if (do_expansion)
	{
		tmp = parameter_expansion(*line, env_dict);
		func_guard(write(heredoc_fd, tmp, ft_strlen(tmp)),
			PROGRAM_NAME, "here_doc_action().");
		free(tmp);
	}
	else
		func_guard(write(heredoc_fd, *line, ft_strlen(*line)),
			PROGRAM_NAME, "here_doc_action().");
	func_guard(write(heredoc_fd, "\n", 1),
		PROGRAM_NAME, "here_doc_action().");
	free(*line);
	*line = readline("> ");
}

static int	here_doc_action(char *filename, char *limiter, t_dict *env_dict)
{
	char			*line;
	const char		*limiter_without_quote = quote_removal(limiter);
	const size_t	limiter_len = ft_strlen(limiter_without_quote);
	const int		heredoc_fd = func_guard(
			open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644),
			PROGRAM_NAME, "here_doc_action().");

	line = readline("> ");
	if (line == NULL)
	{
		free((void *)limiter_without_quote);
		return (close(heredoc_fd));
	}
	while (!(ft_strncmp(line, limiter_without_quote, limiter_len + 1) == 0))
	{
		inner_while(heredoc_fd, &line, env_dict, !is_contain_quote(limiter));
		if (line == NULL)
		{
			free((void *)limiter_without_quote);
			return (close(heredoc_fd));
		}
	}
	free(line);
	free((void *)limiter_without_quote);
	return (close(heredoc_fd));
}

static void	switch_here_doc_norm(t_dict *env_dict, int fd)
{
	dict_modi_val_or_new(env_dict, "?", ft_itoa(1));
	func_guard(dup2(fd, 0), PROGRAM_NAME, "here_doc_traverse().");
}

static int	switch_here_doc(t_tree *tree_left, t_list **here_doc_list,
		t_dict *env_dict)
{
	char	*filename;
	char	*filename_dup;
	char	*limiter;
	t_list	*filename_element;
	int		fd;

	fd = func_guard(dup(0), PROGRAM_NAME, "here_doc_traverse().");
	set_signal(1);
	filename = random_path();
	filename_dup = ft_strdup(filename);
	null_guard(filename_dup, PROGRAM_NAME, "here_doc_traverse().");
	filename_element = ft_lstnew(filename_dup);
	null_guard(filename_element, PROGRAM_NAME, "here_doc_traverse().");
	ft_lstadd_back(here_doc_list, filename_element);
	limiter = (char *)tree_left->left;
	here_doc_action(filename, limiter, env_dict);
	free(limiter);
	tree_left->left = filename;
	if (g_signal)
		switch_here_doc_norm(env_dict, fd);
	func_guard(close(fd), PROGRAM_NAME, "here_doc_traverse().");
	set_signal(0);
	return (g_signal);
}

int	here_doc_traverse(t_tree *tree, t_list **here_doc_list, t_dict *env_dict)
{
	int	ret;

	if (tree == NULL
		|| tree->category == TR_WORD
		|| tree->category == TR_REDIRECT_IN
		|| tree->category == TR_REDIRECT_OUT
		|| tree->category == TR_REDIRECT_APPEND)
		return (0);
	if (tree->category == TR_REDIRECT_HERE_DOC)
	{
		ret = switch_here_doc(tree->left, here_doc_list, env_dict);
		g_signal = 0;
		return (ret);
	}
	if (here_doc_traverse(tree->left, here_doc_list, env_dict))
		return (1);
	return (here_doc_traverse(tree->right, here_doc_list, env_dict));
}
