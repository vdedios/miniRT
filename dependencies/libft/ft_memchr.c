/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:32:52 by vde-dios          #+#    #+#             */
/*   Updated: 2019/12/11 16:32:54 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			it;
	unsigned char	*ps;
	unsigned char	uc;

	it = 0;
	ps = (unsigned char *)s;
	uc = (unsigned char)c;
	while (n-- > 0)
	{
		if (*ps == uc)
			return ((void *)ps);
		ps++;
	}
	return (NULL);
}
