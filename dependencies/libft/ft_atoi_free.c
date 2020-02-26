/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:27:18 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/22 17:23:48 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isthespace(int c)
{
	if (c == '\v' || c == '\n' || c == '\t' ||
		c == '\r' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int			ft_atoi_free(char *str)
{
	int sign;
	int nbr;
	int l;

	sign = 1;
	nbr = 0;
	l = ft_strlen(str);
	while (ft_isthespace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	free(str - l);
	str = NULL;
	return (nbr * sign);
}
