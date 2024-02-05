/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:52:02 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/05 13:34:05 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>
#include <stdio.h>

int	isdigit_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (0);
	}
	return (1);
}

static long long	ft_atoll(const char *str, int *in_of_range)
{
	long long	n;
	int			sign;
	int			i;

	n = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i])
	{
		n = n * 10 + sign * (str[i++] - '0');
		if ((n >= 922337203685477580 && str[i] && (str[i] - '0') > 7) || \
				(n <= -922337203685477580 && str[i] && (str[i] - '0') > 8))
			*in_of_range = 0;
	}
	return (n);
}

static int	is_long_long_digit_str(char *str, long long *exit_num)
{
	int	in_of_range;

	in_of_range = 1;
	if (!isdigit_str(str))
		return (0);
	*exit_num = ft_atoll(str, &in_of_range);
	return (in_of_range);
}

void	builtin_exit(t_exe_lst *exes)
{
	long long	exit_num;
	t_exe_node	*exe;

	if (exes->size == 1)
	{
		ft_putendl_fd(BTIN_EXIT, STDERR_FILENO);
		exit(0);
	}
	exe = exes->head->next;
	if (!is_long_long_digit_str(exe->word, &exit_num))
	{
		ft_putendl_fd(BTIN_EXIT, STDERR_FILENO);
		print_error(BTIN_EXIT, exe->word, "numeric argument required");
		exit(255);
	}
	else if (exes->size > 2)
	{
		ft_putendl_fd(BTIN_EXIT, STDERR_FILENO);
		print_error(BTIN_EXIT, NULL, "too many arguments");
		return ;
	}
	if (DEBUG)
		printf("exit_num: %lld\n", exit_num);
	ft_putendl_fd(BTIN_EXIT, STDERR_FILENO);
	exit(exit_num);
}
