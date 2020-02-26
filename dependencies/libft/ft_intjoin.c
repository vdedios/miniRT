/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:46:19 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/21 21:14:57 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a new
** string, result of the concatenation of s1 and s2.
*/

#include "libft.h"

int		*ft_intjoin(int *s1, int *s2)
{
	int		*joint;
	size_t	l;
	size_t	i;
	size_t	j;

	l = ft_intlen(s1) + ft_intlen(s2) + 1;
	if (!(joint = malloc(l * sizeof(int))))
		return (NULL);
	l = 0;
	i = 0;
	j = 0;
	while (l < (ft_intlen(s1) + ft_intlen(s2)))
	{
		if (l < ft_intlen(s1))
			joint[l++] = s1[i++];
		else
			joint[l++] = s2[j++];
	}
	joint[l] = -1;
	free(s1);
	free(s2);
	s1 = NULL;
	s2 = NULL;
	return (joint);
}
