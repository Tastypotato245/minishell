/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:20:49 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:22:46 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BONUS_H
# define MINISHELL_BONUS_H

# ifndef DEBUG
#  define DEBUG (0)
# endif

# define PROGRAM_NAME "minishell"
# define DEFAULT_PATH "/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin:."

extern int	g_signal;

#endif
