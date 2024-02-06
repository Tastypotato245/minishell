/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_document.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:38:37 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/05 15:49:04 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <_ctype.h>
#include <panic.h>
#include <minishell.h>
#include <here_document.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <unistd.h>
#include <signal_handler.h>

static char	*random_path(void)
{
	int				urandom_fd;
	unsigned char	b;
	int				i;
	char			*random;

	random = null_guard(ft_calloc(70, sizeof(char)),
			PROGRAM_NAME, "random64().");
	ft_strlcpy(random, "/tmp/", 70);
	urandom_fd = func_guard(open("/dev/urandom", O_RDONLY),
			PROGRAM_NAME, "random64().");
	i = 0;
	while (i < 64)
	{
		func_guard(read(urandom_fd, &b, 1), PROGRAM_NAME, "random64().");
		random[i + 5] = "01234567890abcdef"[b % 16];
		i++;
	}
	close(urandom_fd);
	return (random);
}

static int	here_doc_action(char *filename, char *limiter)
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
		func_guard(write(heredoc_fd, line, ft_strlen(line)),
			PROGRAM_NAME, "here_doc_action().");
		func_guard(write(heredoc_fd, "\n", 1),
			PROGRAM_NAME, "here_doc_action().");
		free(line);
		line = readline("> ");
		if (line == NULL)
			return (close(heredoc_fd));
	}
	free(line);
	close(heredoc_fd);
	return (0);
}

static int	switch_here_doc(t_tree *tree_left, t_list **here_doc_list)
{
	char	*filename;
	char	*filename_dup;
	char	*limiter;
	t_list	*filename_element;
	int		fd;

	fd = func_guard(dup(0), PROGRAM_NAME, "here_doc_traverse().");
	set_signal_for_heredoc();
	filename = random_path();
	filename_dup = ft_strdup(filename);
	null_guard(filename_dup, PROGRAM_NAME, "here_doc_traverse().");
	filename_element = ft_lstnew(filename_dup);
	null_guard(filename_element, PROGRAM_NAME, "here_doc_traverse().");
	ft_lstadd_back(here_doc_list, filename_element);
	limiter = (char *)tree_left->left;
	here_doc_action(filename, limiter);
	free(limiter);
	tree_left->left = filename;
	if (g_signal)
		func_guard(dup2(fd, 0), PROGRAM_NAME, "here_doc_traverse().");
	func_guard(close(fd), PROGRAM_NAME, "here_doc_traverse().");
	set_signal();
	return (g_signal);
}

void	unlink_here_doc_temp_file(t_list **here_doc_list)
{
	t_list	*node;

	node = *here_doc_list;
	while (node)
	{
		func_guard(unlink(node->content),
			PROGRAM_NAME, "unlink_here_doc_temp_file().");
		node = node->next;
	}
	ft_lstclear(here_doc_list, free);
}

int	here_doc_traverse(t_tree *tree, t_list **here_doc_list)
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
		ret = switch_here_doc(tree->left, here_doc_list);
		g_signal = 0;
		return (ret);
	}
	if (here_doc_traverse(tree->left, here_doc_list))
		return (1);
	return (here_doc_traverse(tree->right, here_doc_list));
}
