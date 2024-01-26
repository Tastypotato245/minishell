/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:40:00 by kyusulee          #+#    #+#             */
/*   Updated: 2023/10/15 16:41:57 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (srclen + dstsize);
	dstlen = ft_strlen(dst);
	if (dstlen >= dstsize)
		return (srclen + dstsize);
	i = 0;
	while (src[i] && i < dstsize - dstlen - 1)
	{
		dst[dstlen + i] = src[i];
		++i;
	}
	dst[dstlen + i] = 0;
	return (dstlen + srclen);
}
