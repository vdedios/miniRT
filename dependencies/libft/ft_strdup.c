/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:33:39 by vde-dios          #+#    #+#             */
/*   Updated: 2019/12/11 16:33:41 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	it;
	char	*s2;
	size_t	size;

	it = 0;
	size = ft_strlen(s1);
	if (!(s2 = malloc(sizeof(char) * size + 1)))
		return (0);
	while (it < size)
	{
		s2[it] = s1[it];
		it++;
	}
	s2[it] = '\0';
	return (s2);
}
