/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:04:59 by vde-dios          #+#    #+#             */
/*   Updated: 2019/12/03 14:16:38 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Applies the function f to each character of
** the string passed as argument to create a new
** string (with malloc(3)) resulting from successive
** applications of f.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s_f;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(s_f = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		s_f[i] = f(i, s[i]);
		i++;
	}
	s_f[i] = '\0';
	return (s_f);
}
