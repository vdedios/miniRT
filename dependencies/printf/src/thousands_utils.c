/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thousands_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:51:47 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/22 15:47:23 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_mix_strings(char *aux2, char *str, int i)
{
	aux2[0] = str[i - 3];
	aux2[1] = str[i - 2];
	aux2[2] = str[i - 1];
	aux2[3] = '\0';
}

char	*ft_thousands_sep(char *str, t_format format)
{
	int		i;
	int		new_size;
	char	*aux1;
	char	*aux2;

	i = ft_strlen(str);
	new_size = ft_strlen(str) + (int)(ft_strlen(str) / 3);
	if (!(aux1 = malloc(new_size * sizeof(char) + 1)))
		return (NULL);
	if (!(aux2 = malloc(4 * sizeof(char))))
		return (NULL);
	while (i > 3)
	{
		ft_mix_strings(aux2, str, i);
		aux2 = ft_strjoin_second(format.flags->apostrophe, aux2);
		aux1 = ft_strjoin_second(aux2, aux1);
		i -= 3;
	}
	aux2[i] = '\0';
	while (i-- >= 0)
		aux2[i] = str[i];
	aux1 = ft_strjoin(aux2, aux1);
	free(format.flags->apostrophe);
	format.flags->apostrophe = NULL;
	return (aux1);
}

void	ft_separate_float(int i, char *integer, char *decimal, char *str)
{
	int	k;
	int	j;

	k = -1;
	j = 0;
	while (k++ < i - 1)
		integer[k] = str[k];
	integer[k] = '\0';
	k--;
	while (k++ < (int)ft_strlen(str))
		decimal[j++] = str[k];
	decimal[j] = '\0';
}
