/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:30:32 by vde-dios          #+#    #+#             */
/*   Updated: 2019/12/12 09:13:34 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t len;
	size_t cont;

	len = 0;
	cont = 0;
	while (dst[cont] && cont < dstsize)
		cont++;
	len = cont;
	while (src[cont - len] && cont + 1 < dstsize)
	{
		dst[cont] = src[cont - len];
		cont++;
	}
	if (len < dstsize)
		dst[cont] = '\0';
	return (len + ft_strlen(src));
}
