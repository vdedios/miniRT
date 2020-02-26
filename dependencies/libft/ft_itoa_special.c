/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:00:28 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/22 17:24:32 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a string
** representing the integer received as an argument.
** Negative numbers must be handled.
*/

#include "libft.h"

static int	ft_size_num(long long int n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (n < 0)
		n = -n;
	i++;
	if (!n)
		return (i + 2);
	while (n > 0)
	{
		n /= 10;
		j++;
	}
	if (j == 1)
		i = i + j + 1;
	else
		i = i + j;
	return (i);
}

char		*ft_itoa_special(long long int n)
{
	int			size;
	int			i;
	char		*num;

	i = 0;
	size = ft_size_num(n);
	if (!(num = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	if (n < 0)
	{
		n = -n;
		num[i++] = '-';
	}
	else
		num[i++] = '+';
	if (n / 10 == 0)
		num[i++] = '0';
	num[size] = '\0';
	while (i < size)
	{
		num[--size] = (n % 10) + '0';
		n = n / 10;
	}
	return (num);
}
