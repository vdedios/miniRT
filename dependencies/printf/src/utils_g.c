/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_g.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:17:17 by vde-dios          #+#    #+#             */
/*   Updated: 2020/02/11 14:59:26 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_check_trim(char *num)
{
	int i;

	i = 0;
	while (num[i] != '.' && num[i])
		i++;
	if (i == (int)ft_strlen(num))
		return (1);
	return (0);
}

char		*ft_trim_f_zeros(char *num)
{
	int		i;
	int		j;
	char	*num_trimmed;

	if (ft_check_trim(num))
		return (num);
	j = 0;
	i = ft_strlen(num);
	i--;
	while (num[i] == '0')
		i--;
	if (!(num_trimmed = malloc((ft_strlen(num) - i) * sizeof(char))))
		return (NULL);
	if (num[i] == '.')
		i--;
	while (j < i + 1)
	{
		num_trimmed[j] = num[j];
		j++;
	}
	num_trimmed[j] = '\0';
	free(num);
	num = NULL;
	return (num_trimmed);
}

char		*ft_trim_e_zeros(char *num)
{
	int		i;
	int		k;
	char	*num_trimmed;

	k = 0;
	i = ft_strlen(num) - 5;
	while (num[i] == '0')
		i--;
	if (num[i] == '.')
		i--;
	if (!(num_trimmed = malloc((ft_strlen(num) - i + 5) * sizeof(char))))
		return (NULL);
	while (k < i + 1)
	{
		num_trimmed[k] = num[k];
		k++;
	}
	i = ft_strlen(num) - 4;
	while (num[i])
		num_trimmed[k++] = num[i++];
	num_trimmed[k] = '\0';
	free(num);
	num = NULL;
	return (num_trimmed);
}

/*
** As found in C11 standard, %g conversion must be:
** if P > X ≥ −4, the conversion is with style f (or F)
** and precision P − (X + 1). Otherwise, the conversion
** is with style e (or E) and precision P − 1.
** In both cases insignificant trailing zeros are removed
** from the significand, and the decimal point is also
** removed if there are no remaining digits following it.
** A precision of 0 is treated as equivalent to a
** precision of 1
** Precision is not the number of decimals to be output
** but the number of significant digits required. X is
** the exp you would get if number is represented with %e
** with such significant numbers.
*/

static void	ft_significative_exp(double num, int *exp, t_format format)
{
	char	*tmp;

	format.precision--;
	tmp = ft_exp_str(num, exp, format);
	free(tmp);
	tmp = NULL;
	format.precision++;
}

char		*ft_g_conv(double num, int *exp, t_format format)
{
	if (format.type == 'G')
		format.type = 'E';
	else
		format.type = 'e';
	if (format.precision == 0)
		format.precision = 1;
	ft_significative_exp(num, exp, format);
	*exp = -(*exp);
	if (format.precision > *exp && *exp >= -4)
	{
		format.precision = format.precision - (*exp + 1);
		if (format.flags->hash)
			return (ft_float_str(num, format));
		else
			return (ft_trim_f_zeros(ft_float_str(num, format)));
	}
	format.precision = format.precision - 1;
	if (format.flags->hash)
		return (ft_exp_str(num, exp, format));
	else
		return (ft_trim_e_zeros(ft_exp_str(num, exp, format)));
}
