/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:15:51 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/23 15:20:57 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

double					ft_ten_power(int p)
{
	double	t;
	int		i;

	t = 1;
	i = 0;
	if (p < 0)
	{
		p = -p;
		while (i++ < p)
			t = t / 10;
	}
	else if (p > 0)
		while (i++ < p)
			t = t * 10;
	return (t);
}

/*
** Rounds to the even
*/

unsigned long long		ft_rounding(unsigned long long *i_num,
		unsigned long long f_num, double num, int precision)
{
	double f_aux;

	f_aux = f_num;
	if (precision <= 0)
	{
		if (*i_num + 0.5 < num)
			*i_num = *i_num + 1;
		else if (*i_num + 0.5 == num)
		{

			if ((*i_num % 10) % 2)
				*i_num = *i_num + 1;
		}
		return (*i_num);
	}
	if ((f_num + 0.5) * ft_ten_power(18) < (num - *i_num) * ft_ten_power(precision + 18))
		f_num = (f_num + 1) % (long long int)ft_ten_power(precision);
	else if (f_num + 0.5 == (num - *i_num) * ft_ten_power(precision))
	{
		if ((f_num % 10) % 2)
			f_num = (f_num + 1) % (long long int)ft_ten_power(precision);
	}
	if (f_aux && !f_num)
		*i_num = *i_num + 1;
	return (f_num);
}

char					*ft_add_zeroes(char *f_str, int precision)
{
	int					decimals;
	int					i;

	decimals = 0;
	i = ft_strlen(f_str);
	while (decimals++ < precision - (int)i)
		f_str = ft_strjoin_second("0", f_str);
	return (f_str);
}

static char				*ft_check_neg(double *num)
{
	if (*num < 0)
	{
		*num = -(*num);
		return ("-");
	}
	return (0);
}

char					*ft_float_str(double num, t_format format)
{
	unsigned long long	i_num;
	unsigned long long	f_num;
	char				*f_str;
	char				*i_str;

	i_str = ft_check_neg(&num);
	i_num = (num);
	f_num = num * ft_ten_power(format.precision) -
		i_num * ft_ten_power(format.precision);
	if (format.precision <= 0)
	{
		i_num = ft_rounding(&i_num, f_num, num, format.precision);
		i_str = ft_strjoin_second(i_str, ft_itoa(i_num));
		if (format.flags->hash)
			i_str = ft_strjoin_first(i_str, ".");
		return (i_str);
	}
	f_num = ft_rounding(&i_num, f_num, num, format.precision);
	i_str = ft_strjoin_second(i_str, ft_itoa(i_num));
	i_str = ft_strjoin_first(i_str, ".");
	f_str = ft_itoa(f_num);
	f_str = ft_add_zeroes(f_str, format.precision);
	return (ft_strjoin(i_str, f_str));
}
