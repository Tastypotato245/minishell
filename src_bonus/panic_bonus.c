/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <kyusulee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:09:08 by kyusulee          #+#    #+#             */
/*   Updated: 2024/02/08 13:09:11 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <panic_bonus.h>

void	panic(char *error_message)
{
	printf("error: %s\n", error_message);
	exit(1);
}
