/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_xXp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:18:40 by vde-dios          #+#    #+#             */
/*   Updated: 2020/02/01 16:24:38 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** Decimal to hex conversion applying bit shift
*/

void					ft_print_hex(char *hex, long long int num, char uplow)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (!(num & (LONG_MASK >> i)) && (i < 64))
		i += 4;
	if (i >= 64)
	{
		hex[j] = '0';
		j++;
	}
	while (i < 64)
	{
		hex[j] = (num & (LONG_MASK >> i)) >> (60 - i);
		if (hex[j] > 9)
			hex[j] = hex[j] + uplow - 33;
		else
			hex[j] = hex[j] + '0';
		i += 4;
		j++;
	}
	hex[j] = '\0';
}
