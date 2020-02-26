/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:36:21 by vde-dios          #+#    #+#             */
/*   Updated: 2020/02/11 14:59:50 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_set_spaces(int num, char symbol)
{
	char	*spaces;
	int		i;

	i = 0;
	if (num > 0)
	{
		if (!(spaces = malloc(num * sizeof(char) + 1)))
			return (NULL);
		while (i < num)
			spaces[i++] = symbol;
		spaces[i] = '\0';
		return (spaces);
	}
	else
		return (NULL);
}

char		*ft_trim_string(char *str, int pos)
{
	char	*trimmed;
	int		i;

	i = 0;
	if (!(trimmed = malloc(pos * sizeof(char))))
		return (NULL);
	while (i < pos && str[i])
	{
		trimmed[i] = str[i];
		i++;
	}
	trimmed[i] = '\0';
	free(str);
	str = NULL;
	return (trimmed);
}

static void	ft_set_width(t_format *format, char *str)
{
	format->width = format->width - (int)ft_strlen(str) -
	((format->flags->hash && (format->type == 'x' ||
	format->type == 'X')) ? 2 : 0) -
	((format->flags->plus && format->flags->zero) ? 1 : 0)
	- ((format->flags->space && str[0] != '-') ? 1 : 0);
}

char		*ft_width(t_format *format, char *str)
{
	if (format->flags->zero && !format->flags->minus
	&& (format->precision == -1 || format->type == 'f' ||
	format->type == 'F' || format->type == 'e' ||
	format->type == 'E' || format->type == 'g' || format->type == 'G'))
	{
		if (format->width > (int)ft_strlen(str))
		{
			if (str[0] == '-')
			{
				str[0] = '0';
				format->width = format->width - ft_strlen(str) - 1;
				str = ft_strjoin(ft_set_spaces(format->width, '0'), str);
				return (ft_strjoin_second("-", str));
			}
			ft_set_width(format, str);
			return (ft_strjoin(ft_set_spaces(format->width, '0'), str));
		}
	}
	ft_set_width(format, str);
	if (format->flags->minus)
		return (ft_strjoin(str, ft_set_spaces(format->width, ' ')));
	else
		return (ft_strjoin(ft_set_spaces(format->width, ' '), str));
}

char		*ft_precision(t_format format, char *str)
{
	if (format.type == 'd' || format.type == 'i' ||
			format.type == 'u' || format.type == 'x'
			|| format.type == 'X' || (format.type == 'p'
				&& format.precision))
	{
		if (format.precision > (int)ft_strlen(str) ||
				(str[0] == '-' && format.precision >= (int)ft_strlen(str)))
		{
			if (str[0] == '-')
			{
				str[0] = '0';
				format.precision = format.precision - ft_strlen(str);
				str = ft_strjoin(ft_set_spaces(format.precision, '0'), str);
				return (ft_strjoin_second("-", str));
			}
			format.precision = format.precision - ft_strlen(str);
			return (ft_strjoin(ft_set_spaces(format.precision, '0'), str));
		}
		return (str);
	}
	else if (format.type == 's' || format.type == 'p')
		return (ft_trim_string(str, format.precision));
	return (0);
}
