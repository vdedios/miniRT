/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:42:24 by vde-dios          #+#    #+#             */
/*   Updated: 2019/12/20 16:54:18 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a substring
** from the string given in argument.
** The substring begins at index ’start’ and is of
** maximum size ’len’.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	j;

	j = 0;
	if (!s)
		return (0);
	if (!(ret = malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (j < len && s[start])
			ret[j++] = s[start++];
	}
	ret[j] = '\0';
	return (ret);
}
