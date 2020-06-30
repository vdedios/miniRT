/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_e_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:45:06 by vde-dios          #+#    #+#             */
/*   Updated: 2020/06/30 11:45:37 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int							ft_count_figures(long long int num)
{
	int d;

	d = 0;
	while (num)
	{
		num = num / 10;
		d++;
	}
	return (d);
}

unsigned long long			ft_get_integer(double num, char type, int *exp)
{
	unsigned long long	i_num;
	int					i;

	i = 0;
	if (*((long long int *)&num) == 0)
		return (0);
	i_num = (int)num;
	while (ft_count_figures(i_num) != 1)
	{
		if (ft_count_figures(i_num) < 1)
		{
			i++;
			i_num = (long long int)(num * ft_ten_power(i));
		}
		else
		{
			i--;
			i_num = (long long int)num * ft_ten_power(i);
		}
	}
	*exp = i;
	if (type == 'i')
		return (i_num);
	else
		return (i);
}
