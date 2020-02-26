/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:57:15 by vde-dios          #+#    #+#             */
/*   Updated: 2019/12/03 14:32:27 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns an array of
** strings obtained by splitting s using the character
** c as a delimiter. The array must be ended by a
** NULL pointer.
*/

#include "libft.h"

static size_t		ft_count_words(char const *s, char c)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	if (!*s)
		return (0);
	if (*s != c)
		i++;
	while (j < ft_strlen(s) - 1)
	{
		if (s[j] == c && s[j + 1] != c)
			i++;
		j++;
	}
	return (i);
}

static	char		*ft_get_word(char const *s, char c)
{
	size_t	j;
	size_t	k;
	char	*word;

	k = 0;
	j = 0;
	while (s[j] != c && s[j])
		j++;
	if (!(word = (char *)malloc((j + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(word, s, j + 1);
	return (word);
}

static char			**ft_free_all(char **matrix, size_t i)
{
	while (i)
		free(matrix[i--]);
	free(matrix);
	return (0);
}

char				**ft_split(char const *s, char c)
{
	char	**matrix;
	size_t	i;
	size_t	matrix_size;

	i = 0;
	if (!s)
		return (0);
	matrix_size = ft_count_words(s, c);
	if (!(matrix = (char **)malloc((matrix_size + 1) * sizeof(char*))))
		return (NULL);
	while (i < matrix_size)
	{
		while (*s == c)
			s++;
		if (!(matrix[i] = ft_get_word(s, c)))
			return (ft_free_all(matrix, i));
		s += ft_strlen(matrix[i]);
		i++;
	}
	matrix[i] = 0;
	return (matrix);
}
