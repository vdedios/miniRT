/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_join_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 17:55:29 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/10 17:04:40 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_second(char *s1, char *s2)
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
	free(s2);
	s2 = NULL;
	return (joint);
}
