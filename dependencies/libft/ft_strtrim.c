/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:49:13 by vde-dios          #+#    #+#             */
/*   Updated: 2019/12/03 14:18:26 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a copy of
** the string given as argument without the characters
** specified in the set argument at the beginning and
** the end of the string.
*/

#include "libft.h"

static char const	*ft_strrev(char const *s1)
{
	char	*aux;
	size_t	l;
	size_t	i;

	i = 0;
	l = ft_strlen(s1);
	if (!(aux = (char *)malloc((l + 1) * sizeof(char))))
		return (NULL);
	while (*s1)
		s1++;
	s1--;
	while (i < l)
	{
		*aux++ = *s1--;
		i++;
	}
	*aux = '\0';
	return (char const*)(aux - l);
}

static size_t		ft_position(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
	{
		while (j < ft_strlen(set))
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (j >= ft_strlen(set))
			return (i);
		j = 0;
		i++;
	}
	return (i);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	i;
	size_t	f;

	if (!s1 || !set)
		return (0);
	if (!(trim = malloc(ft_strlen(s1) * sizeof(char))))
		return (NULL);
	*trim = '\0';
	i = ft_position(s1, set);
	s1 = ft_strrev(s1);
	f = (unsigned int)ft_position(s1, set);
	s1 = ft_strrev(s1);
	if (f == ft_strlen(s1))
		return (trim);
	f = (size_t)ft_strlen(s1) - i - f;
	trim = ft_substr(s1, i, f);
	return (trim);
}
