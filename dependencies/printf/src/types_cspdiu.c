/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_cspdiu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:16:13 by vde-dios          #+#    #+#             */
/*   Updated: 2020/02/02 20:05:46 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** <<c>> type conversion
*/

char	*ft_c_conv(t_format *format, va_list args, int pos)
{
	char	*aux;
	int		*pos_zero;

	(void)format;
	if (!(aux = malloc(2 * sizeof(char))))
		return (NULL);
	*aux = va_arg(args, int);
	*(aux + 1) = '\0';
	if (*aux == '\0')
	{
		if (!(pos_zero = malloc(2 * sizeof(int))))
			return (NULL);
		*aux = 1;
		pos_zero[0] = pos;
		format->last_pos = pos;
		pos_zero[1] = -1;
		format->print_l = ft_intjoin(format->print_l, pos_zero);
	}
	return (aux);
}

/*
** <<s>> type conversion
*/

char	*ft_s_conv(t_format format, va_list args)
{
	char	*aux;

	(void)format;
	aux = va_arg(args, char *);
	if (aux)
		aux = ft_strjoin_none(aux, NULL);
	else
		aux = ft_strjoin_none("(null)", NULL);
	if (format.precision != -1)
		return (ft_precision(format, aux));
	return (aux);
}

/*
** <<p>> type conversion
*/

char	*ft_p_conv(t_format format, va_list args)
{
	long int	dir;
	long int	aux;
	int			size;
	char		*hex;

	(void)format;
	size = 0;
	dir = (long int)va_arg(args, void *);
	aux = dir;
	while (aux)
	{
		aux = aux / 10;
		size++;
	}
	if (!(hex = malloc(size * sizeof(char))))
		return (NULL);
	if (format.precision != -1 && dir == 0)
		return (ft_strjoin_second("0x", ft_precision(format, hex)));
	ft_print_hex(hex, dir, 'x');
	hex = ft_strjoin_second("0x", hex);
	return (hex);
}

/*
** <<d/i>> type conversion
*/

char	*ft_di_conv(t_format format, va_list args)
{
	long long int		num;

	(void)format;
	if (format.length == 'l')
		num = va_arg(args, long int);
	else if (format.length == 'L')
		num = va_arg(args, long long int);
	else if (format.length == 'h')
		num = (short)va_arg(args, int);
	else if (format.length == 'H')
		num = (char)va_arg(args, int);
	else
		num = va_arg(args, int);
	if (format.precision)
		return (ft_precision(format, ft_itoa(num)));
	else if (!format.precision && !num)
		return (ft_strjoin_none(NULL, NULL));
	return (ft_itoa(num));
}

/*
** <<u>> type conversion
*/

char	*ft_u_conv(t_format format, va_list args)
{
	unsigned long long int	num;

	(void)format;
	if (format.length == 'l')
		num = va_arg(args, unsigned long int);
	else if (format.length == 'L')
		num = va_arg(args, unsigned long long int);
	else if (format.length == 'h')
		num = (unsigned short)va_arg(args, unsigned int);
	else if (format.length == 'H')
		num = (unsigned char)va_arg(args, unsigned int);
	else
		num = va_arg(args, unsigned int);
	if (format.precision)
		return (ft_precision(format, ft_uitoa(num)));
	else if (!format.precision && !num)
		return (ft_strjoin_none(NULL, NULL));
	return (ft_uitoa(num));
}
