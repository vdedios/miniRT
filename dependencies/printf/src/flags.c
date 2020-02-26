/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:27:31 by vde-dios          #+#    #+#             */
/*   Updated: 2020/02/01 18:20:36 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_plus(char *str, t_format *format)
{
	format->flags->plus = 0;
	format->flags->space = 0;
	if (str[0] != '-')
		return (ft_strjoin_second("+", str));
	else
		return (str);
}

char	*ft_hash(char *str, t_format *format)
{
	format->flags->hash = 0;
	if (format->type == 'x')
		return (ft_strjoin_second("0x", str));
	if (format->type == 'X')
		return (ft_strjoin_second("0X", str));
	return (str);
}

char	*ft_space(char *str, t_format format)
{
	int	i;

	i = 0;
	while (str[i] != '-' && str[i])
		i++;
	if (i == (int)ft_strlen(str))
	{
		if (!format.flags->plus && format.type != '%')
			return (ft_strjoin_second(" ", str));
	}
	return (str);
}

char	*ft_apostrophe(char *str, t_format format)
{
	char	*decimal;
	char	*integer;
	int		i;

	i = 0;
	if (format.type == 'd' || format.type == 'i' || format.type == 'u')
		str = ft_thousands_sep(str, format);
	if (format.type == 'f' || format.type == 'g')
	{
		while (str[i] != '.')
			i++;
		if (i > 2)
		{
			if (!(integer = malloc((i) * sizeof(char))))
				return (NULL);
			if (!(decimal = malloc((ft_strlen(str) - i + 1) * sizeof(char))))
				return (NULL);
			ft_separate_float(i, integer, decimal, str);
			integer = ft_thousands_sep(integer, format);
			free(str);
			str = NULL;
			return (ft_strjoin(integer, decimal));
		}
	}
	return (str);
}
