/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_document.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:38:37 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/07 16:10:59 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <panic.h>
#include <minishell.h>
#include <here_document.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <unistd.h>
#include <signal_handler.h>
#include <expansion.h>

static int	is_contain_quote(char *limiter)
{
	const size_t	limiter_len = ft_strlen(limiter);
	size_t			i;

	i = 0;
	while (i < limiter_len)
	{
		if (ft_strchr("\"\'", limiter[i]))
			return (1);
		i++;
	}
	return (0);
}

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
	const size_t	limiter_len = ft_strlen(limiter);
	char			*line;
	int				heredoc_fd;

	heredoc_fd = func_guard(open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644),
			PROGRAM_NAME, "here_doc_action().");
	line = readline("> ");
	if (line == NULL)
		return (close(heredoc_fd));
	while (ft_strlen(line) > 0
		&& !(ft_strncmp(line, limiter, limiter_len + 1) == 0))
	{
		inner_while(heredoc_fd, &line, env_dict, !is_contain_quote(limiter));
		if (line == NULL)
			return (close(heredoc_fd));
	}
	free(line);
	close(heredoc_fd);
	return (0);
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
