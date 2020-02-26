/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:33:10 by vde-dios          #+#    #+#             */
/*   Updated: 2019/12/11 16:33:12 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *pdst;
	unsigned char *psrc;

	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	if (n == 0 || src == dst)
	{
		return (dst);
	}
	while (n-- > 0)
	{
		*(pdst++) = *(psrc++);
	}
	return (dst);
}
