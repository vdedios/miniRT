/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:17:00 by vde-dios          #+#    #+#             */
/*   Updated: 2020/02/11 14:55:33 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int					ft_round_exp_max(t_format format,
							unsigned long long *i_num,
							unsigned long long *f_num)
{
	long long int	f_aux;
	long long int	i_aux;

	i_aux = *i_num * ft_ten_power(format.precision) +
		*f_num / ft_ten_power(15 - format.precision);
	f_aux = *f_num - (long long)(*f_num / ft_ten_power(15 - format.precision))
		* ft_ten_power(15 - format.precision);

	if (5 * ft_ten_power(15 - format.precision - 1) < f_aux)
	{
		return (1);
	}
	else if (5 * ft_ten_power(15 - format.precision - 1) == f_aux)
	{
		if ((i_aux % 10) % 2)
			return (1);
	}
	return (0);
}

static void					ft_round_exp(t_format format,
							unsigned long long *i_num,
							unsigned long long *f_num, int *exp)
{
	unsigned long long	i_aux;
	unsigned long long	f_aux;

	f_aux = *i_num * ft_ten_power(format.precision) +
		*f_num / ft_ten_power(15 - format.precision);
	i_aux = (*i_num * ft_ten_power(format.precision + 1)) +
		(*f_num / ft_ten_power(15 - format.precision - 1));
	if (ft_round_exp_max(format, i_num, f_num))
	{
		i_aux = f_aux;
		f_aux = f_aux + 1;
	}
	if (ft_count_figures(f_aux) > ft_count_figures(i_aux))
	{
		*exp = *exp - 1;
		format.precision = format.precision + 1;
	}
	*i_num = f_aux / (unsigned long long)ft_ten_power(format.precision);
	*f_num = f_aux % (unsigned long long)ft_ten_power(format.precision);
}

char						*ft_get_decimals(unsigned long long f_num, int *exp,
		t_format format)
{
	char	*f_str;

	f_str = ft_itoa(f_num);
	f_str = ft_add_zeroes(f_str, format.precision);
	if (!format.precision)
	{
		free(f_str);
		f_str = NULL;
	}
	if (format.type == 'e')
		f_str = ft_strjoin_first(f_str, "e");
	else
		f_str = ft_strjoin_first(f_str, "E");
	f_str = ft_strjoin(f_str, ft_itoa_special(-*exp));
	return (f_str);
}

char						*ft_exp_str(double num, int *exp, t_format format)
{
	unsigned long long	i_num;
	unsigned long long	f_num;
	char				*f_str;
	char				*i_str;

	i_str = 0;
	if (num < 0)
	{
		num = -num;
		i_str = "-";
	}
	i_num = ft_get_integer(num, 'i', exp);
	f_num = num * ft_ten_power(15 + *exp) -
		(unsigned long long)(num * ft_ten_power(*exp)) *
		ft_ten_power(15);
	ft_round_exp(format, &i_num, &f_num, exp);
	i_str = ft_strjoin_second(i_str, ft_itoa(i_num));
	f_str = ft_get_decimals(f_num, exp, format);
	if (format.precision != 0 || format.flags->hash)
		i_str = ft_strjoin_first(i_str, ".");
	return (ft_strjoin(i_str, f_str));
}
