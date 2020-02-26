/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:46:19 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/20 15:27:40 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a new
** string, result of the concatenation of s1 and s2.
*/

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joint;
	size_t	l;
	size_t	i;
	size_t	j;

	l = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(joint = malloc(l * sizeof(char))))
		return (NULL);
	l = 0;
	i = 0;
	j = 0;
	while (l < (ft_strlen(s1) + ft_strlen(s2)))
	{
		if (l < ft_strlen(s1))
			joint[l++] = s1[i++];
		else
			joint[l++] = s2[j++];
	}
	joint[l] = '\0';
	free(s1);
	free(s2);
	s1 = NULL;
	s2 = NULL;
	return (joint);
}
