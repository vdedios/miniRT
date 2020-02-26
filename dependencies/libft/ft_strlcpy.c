/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:33:55 by vde-dios          #+#    #+#             */
/*   Updated: 2019/12/12 10:58:32 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	int		it;

	if (!dst)
		return (0);
	it = 0;
	len = ft_strlen(src);
	while (src[it] != '\0' && it < (int)(dstsize - 1))
	{
		dst[it] = src[it];
		it++;
	}
	if (dstsize)
		dst[it] = '\0';
	return (len);
}
