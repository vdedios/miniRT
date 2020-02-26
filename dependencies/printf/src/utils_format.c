/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:07:37 by vde-dios          #+#    #+#             */
/*   Updated: 2020/02/01 18:05:12 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

short		ft_check_flags(t_format *format, char set)
{
	(void)format;
	if (set == '0')
		format->flags->zero = 1;
	else if (set == '+')
		format->flags->plus = 1;
	else if (set == '-')
		format->flags->minus = 1;
	else if (set == '#')
		format->flags->hash = 1;
	else if (set == ' ')
		format->flags->space = 1;
	else if (set == 39)
	{
		if (!(format->flags->apostrophe =
					malloc(2 * sizeof(char))))
			return (0);
		format->flags->apostrophe[0] = ',';
		format->flags->apostrophe[1] = '\0';
	}
	if (format->flags->minus && format->flags->zero)
		format->flags->zero = 0;
	if (format->flags->space && format->flags->plus)
		format->flags->space = 0;
	return (1);
}

static char	*ft_num_noarg(int j, int *i, char *format_info)
{
	int		k;
	char	*num;

	k = 0;
	while (format_info[j] >= '0' && format_info[j] <= '9')
		j++;
	if (!(num = malloc((j - *i + 1) * sizeof(char))))
		return (0);
	while (*i < j)
	{
		num[k++] = format_info[*i];
		*i = *i + 1;
	}
	num[k] = '\0';
	return (num);
}

int			ft_check_number(char *format_info, int *i,
			va_list args, t_format *format)
{
	int		j;
	int		k;
	char	*num;

	num = NULL;
	if (format_info[*i] == '*')
	{
		k = va_arg(args, int);
		if (k < 0)
		{
			if (format_info[*i - 1] != '.')
				format->flags->minus = 1;
			else if (format_info[*i - 1] == '.')
			{
				*i = *i + 1;
				return (-1);
			}
			k = -k;
		}
		*i = *i + 1;
		return (k);
	}
	j = *i;
	num = ft_num_noarg(j, i, format_info);
	return (ft_atoi_free(num));
}

char		ft_check_length(char *format_info, int *i)
{
	if (format_info[*i + 1] == 'l')
	{
		*i = *i + 2;
		return ('L');
	}
	else if (format_info[*i + 1] == 'h')
	{
		*i = *i + 2;
		return ('H');
	}
	*i = *i + 1;
	return (format_info[*i - 1]);
}

void		ft_classify_format(char *format_info,
				t_format *format, va_list args)
{
	int i;

	i = 1;
	if (format_info)
	{
		while (format_info[i] == '0' || format_info[i] == '+'
				|| format_info[i] == '-' || format_info[i] == '#'
				|| format_info[i] == ' ' || format_info[i] == 39)
		{
			ft_check_flags(format, format_info[i]);
			i++;
		}
		if (format_info[i] > '0' || format_info[i] <= '9'
				|| format_info[i] == '*')
			format->width = ft_check_number(format_info, &i, args, format);
		if (format_info[i] == '.')
		{
			i++;
			format->float_precision = 1;
			format->precision = ft_check_number(format_info, &i, args, format);
		}
		if (format_info[i] == 'h' || format_info[i] == 'l')
			format->length = ft_check_length(format_info, &i);
		format->type = format_info[i];
	}
}
