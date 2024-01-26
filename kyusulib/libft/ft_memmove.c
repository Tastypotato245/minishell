/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:39:46 by kyusulee          #+#    #+#             */
/*   Updated: 2023/10/19 14:31:27 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (dst);
	i = 0;
	if (dst > src)
	{
		while (i < len)
		{
			((char *)dst)[len - 1 - i] = ((char *)src)[len - 1 - i];
			++i;
		}
	}
	else
		return (ft_memcpy(dst, src, len));
	return (dst);
}
