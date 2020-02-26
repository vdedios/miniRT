/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:35:34 by vde-dios          #+#    #+#             */
/*   Updated: 2020/02/01 18:21:30 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_extract_format(const char *s)
{
	int		l;
	int		l_types;
	char	*types;

	l = 1;
	types = "cspdiuxXnfgeFGE%";
	l_types = ft_strlen(types);
	while (s[l] != *types++ && s[l])
	{
		if (!*types)
		{
			types = types - l_types;
			l++;
		}
	}
	if (l < (int)ft_strlen(s))
		return (ft_substr(s, 0, l + 1));
	return (NULL);
}

char	*ft_pre_format(va_list args, t_format *format, char *print_buf)
{
	if (format->type == 'c')
		return (ft_c_conv(format, args, (int)ft_strlen(print_buf)));
	if (format->type == 's')
		return (ft_s_conv(*format, args));
	if (format->type == 'p')
		return (ft_p_conv(*format, args));
	if (format->type == 'd' || format->type == 'i')
		return (ft_di_conv(*format, args));
	if (format->type == 'u')
		return (ft_u_conv(*format, args));
	if (format->type == 'x' || format->type == 'X')
		return (ft_hex_conv(format, args));
	if (format->type == 'f' || format->type == 'e' ||
			format->type == 'g' || format->type == 'F' ||
			format->type == 'E' || format->type == 'G')
		return (ft_floatpoint_conv(*format, args));
	if (format->type == 'n')
		ft_n_conv(*format, args, print_buf);
	if (format->type == '%')
		return (ft_strjoin_none("%", NULL));
	return (0);
}

void	ft_formater(const char **s, char **print_buf,
		va_list args, int **c_nulls)
{
	char		*format_info;
	char		*format_aux;
	t_format	format;
	t_flags		flags;

	format.flags = &flags;
	ft_initialize_format(&format, c_nulls);
	format_info = ft_extract_format(*s);
	ft_classify_format(format_info, &format, args);
	if (format.flags->minus)
		format.flags->zero = 0;
	format_aux = ft_pre_format(args, &format, *print_buf);
	format_aux = ft_post_format(format_aux, &format);
	*print_buf = ft_strjoin(*print_buf, format_aux);
	if (format_info)
		*s = *s + ft_strlen(format_info) - 1;
	else
		*s = *s + ft_strlen(*s) - 1;
	*c_nulls = format.print_l;
	free(format_info);
	format_info = NULL;
}

int		ft_printf(const char *s, ...)
{
	char		*print_buf;
	int			*c_nulls;
	va_list		args;

	va_start(args, s);
	print_buf = NULL;
	c_nulls = NULL;
	while (*s)
	{
		if (*s == '%')
			ft_formater(&s, &print_buf, args, &c_nulls);
		else
			print_buf = ft_strjoin(print_buf, ft_string_to_char((char *)s));
		s++;
	}
	va_end(args);
	return (ft_putstr_len(print_buf, 1, c_nulls));
}
