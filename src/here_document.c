/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_document.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:38:37 by younghoc          #+#    #+#             */
/*   Updated: 2024/02/01 16:38:38 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <panic.h>
#include <minishell.h>
#include <here_document.h>
#include <fcntl.h>
#include <readline/readline.h>

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

void	here_doc_traverse(t_tree *tree, t_list **here_doc_list)
{
	t_tree	*tree_left;
	char	*filename;
	char	*limiter;

	if (tree == NULL
		|| tree->category == TR_WORD
		|| tree->category == TR_REDIRECT_IN
		|| tree->category == TR_REDIRECT_OUT
		|| tree->category == TR_REDIRECT_APPEND)
		return ;
	if (tree->category == TR_REDIRECT_HERE_DOC)
	{
		tree_left = tree->left;
		filename = random_path();
		limiter = (char *)tree_left->left;
		here_doc_action(filename, limiter);
		free(limiter);
		tree->category = TR_REDIRECT_IN;
		tree_left->left = filename;
	}
	else
	{
		here_doc_traverse(tree->left, here_doc_list);
		here_doc_traverse(tree->right, here_doc_list);
	}
}
