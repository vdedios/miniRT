/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:17:04 by vde-dios          #+#    #+#             */
/*   Updated: 2020/02/01 18:24:29 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_string_to_char(char *s)
{
	char *aux;

	if (!(aux = malloc(2 * sizeof(char))))
		return (0);
	*aux = *s;
	*(aux + 1) = '\0';
	return (aux);
}

void	ft_initialize_format(t_format *format, int **c_nulls)
{
	int	i;

	i = 0;
	format->flags->zero = 0;
	format->flags->plus = 0;
	format->flags->minus = 0;
	format->flags->hash = 0;
	format->flags->space = 0;
	format->flags->zero = 0;
	format->flags->apostrophe = NULL;
	format->width = 0;
	format->precision = -1;
	format->float_precision = 0;
	format->length = '\0';
	format->type = '\0';
	format->print_l = *c_nulls;
	format->last_pos = -1;
}

char	*ft_post_format(char *format_aux, t_format *format)
{
	int i;

	i = 0;
	if (format->flags->plus && (!format->flags->zero || (format->precision >= 0 && 
					(format->type != 'f' && format->type != 'g'))))
		format_aux = ft_plus(format_aux, format);
	if (format->flags->apostrophe)
		format_aux = ft_apostrophe(format_aux, *format);
	if (format->flags->hash && (!format->flags->zero || format->precision >= 0))
		format_aux = ft_hash(format_aux, format);
	if (format->width)
		format_aux = ft_width(format, format_aux);
	if (format->flags->space)
		format_aux = ft_space(format_aux, *format);
	if (format->flags->hash)
		format_aux = ft_hash(format_aux, format);
	if (format->flags->plus && format->flags->zero)
		format_aux = ft_plus(format_aux, format);
	if (format->last_pos != -1 && !format->flags->minus)
	{
		while (format->print_l[i] != -1)
			i++;
		i--;
		format->print_l[i] = format->print_l[i] + format->width;
	}
	return (format_aux);
}
